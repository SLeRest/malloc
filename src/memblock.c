/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <sle-rest@42.fr>                    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:56:53 by sle-rest          #+#    #+#             */
/*   Updated: 2019/11/20 15:30:05 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	init_memblock(t_memblock *block, t_memblock *next, size_t size)
{
	block->size = size;
	block->next = next;
	block->is_free = 0;
}

t_memblock	*get_free_memblock(t_page *page, size_t size)
{
	t_memblock	*block;

	block = page->block;
	while (block)
	{
		if (block->is_free && block->next - (block + 1) >= size)
			init_memblock(block, block->next, size);
			return block;
	}
	return NULL;
}

t_memblock	*get_membloc(t_page *page, size_t size)
{
	t_memblock	*block;
	t_memblock *new_block;

	if (page)
	{
		block = get_free_memblock(page, size);
		// c'est bon on a trouver un block free qui a assez d'espace
		if (block)
			return (block);
		// premier block de cette page
		if (!page->block)
		{
			page->block = (void *)page + 1;
			init_memblock(page->block, NULL, size);
			return page->block;
		}
		block = page->block;
		while (block->next)
			block = block->next;
		block->next = (block + 1) + block->size;
		init_memblock(block->next, NULL, size);
		return new_block;
	}
	return NULL;
}
