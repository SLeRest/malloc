/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <sle-rest@42.fr>                    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:55:40 by sle-rest          #+#    #+#             */
/*   Updated: 2019/11/20 15:45:37 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/* Pas sur pour le inferieur ou egale */
int	verify_space(size_t size, t_page *page)
{
	t_memblock	*block;

	if (page)
	{
		if (page->size - page->allocated >= size)
			return (1);
		block = page->block;
		while (block)
		{
			if (block->is_free && block->size <= size)
				return (1);
		}
		return (0);
	}
	return (0);
}
