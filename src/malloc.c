/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <sle-rest@42.fr>                    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:49:08 by sle-rest          #+#    #+#             */
/*   Updated: 2019/11/20 15:49:38 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
	mmap
	munmap
	getpagesize
	getrlimit
*/

void	*malloc(size_t size)
{
	t_page		*page;
	t_memblock	*block;

	printf("lol");
	if (!size)
		return NULL;
	page = get_page_by_size(size);
	// error handler
	block = get_membloc(page, size);
	// error handler
	// log_history(page, block);
	return ((void *)block + 1);
}
