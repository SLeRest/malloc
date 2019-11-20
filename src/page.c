#include "malloc.h"

t_page	**get_first_page()
{
	static t_page	*first = NULL;

	return (&first);
}

void	init_page(t_page *page, size_t size, size_t pagesize)
{
	if (page)
	{
		page->pagesize = pagesize;
		page->pagesize = SMALL;
		page->pagesize = LARGE;
		page->size = size - sizeof(t_page);
		page->allocated = sizeof(t_memblock) + size;
		page->block = NULL; // TODO
	}
}

t_page	*alloc_new_page(t_page **first, size_t size)
{
	t_page	*page;
	size_t	alloc_size;
	int flags;
	int prots;

	page = *first;
	alloc_size = sizeof(t_page) + sizeof(t_memblock);
	alloc_size += size < TINY_SIZE ? TINY_PSIZE : SMALL_PSIZE;
	prots = PROT_READ | PROT_WRITE;
	flags = MAP_ANON | MAP_PRIVATE;
	if (page)
	{
		while (page->next)
			page = page->next;
		page->next = mmap(0,  alloc_size, prots, flags, -1, 0);
		init_page(page->next, size, size < TINY_SIZE ? TINY_PSIZE : SMALL_PSIZE);
		return page->next; // peut retourner NULL
	}
	*first = mmap(0,  alloc_size,  prots, flags, -1, 0);
	init_page(*first, size, size < TINY_SIZE ? TINY_PSIZE : SMALL_PSIZE);
	return *first;
}

t_page	*get_page_by_size(size_t size)
{
	t_page	**first;
	t_page	*page;

	first = get_first_page();
	page = *first;
	while (page)
	{
		if (page->pagesize == TINY && size < TINY_SIZE && verify_space(size, page))
			return (page);
		if (page->pagesize == SMALL && size < SMALL_SIZE && verify_space(size, page))
			return (page);
		if (page->pagesize == LARGE && SMALL_SIZE < size)
			return (page);
		page = page->next;
	}
	page = alloc_new_page(first, size);
	if (!(*first))
		*first = page;
	return page;
}
