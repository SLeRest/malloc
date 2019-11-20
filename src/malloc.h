/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:48:52 by sle-rest          #+#    #+#             */
/*   Updated: 2019/11/20 15:44:39 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_SIZE		(size_t)128
# define SMALL_SIZE		(size_t)1024

# define TINY_PSIZE		(size_t)(getpagesize() * 4)
# define SMALL_PSIZE	(size_t)(getpagesize() * 32)
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

typedef enum					e_pagesize
{
	TINY,
	SMALL,
	LARGE
}								t_pagesize;

typedef enum					e_action
{
	MALLOC,
	FREE,
	REALLOC
}								t_action;

typedef struct					s_page
{
	t_pagesize					pagesize;
	size_t						size;
	size_t						allocated;
	struct s_memblock			*block;
	struct s_page				*next;
}								t_page;

typedef struct					s_memblock
{
	size_t						size;
	int							is_free;
	struct s_memblock			*next;
}								t_memblock;

/*
typedef struct					s_history
{
	struct s_page				*page;
	struct s_memblock			*block;
	struct s_memblock			*old_block; // que en cas de realloc
	t_action					action;
}								t_history;
*/

/* utils.c */
int			verify_space(size_t size, t_page *page);
void		*malloc(size_t size);
t_page		*get_page_by_size(size_t size);
t_memblock	*get_membloc(t_page *page, size_t size);

#endif
