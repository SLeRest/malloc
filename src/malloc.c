/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:49:08 by sle-rest          #+#    #+#             */
/*   Updated: 2019/10/17 11:50:20 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*malloc(size_t size)
{
	static metadata_malloc	*start = NULL;

	if (!start)
}
