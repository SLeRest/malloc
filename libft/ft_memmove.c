/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:19:18 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 21:47:58 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_overlap(unsigned char *cdst, unsigned char *csrc, size_t len)
{
	while (len--)
	{
		if (csrc++ == cdst)
			return (1);
	}
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (ft_is_overlap(cdst, csrc, len))
	{
		cdst += len;
		csrc += len;
		while (len--)
			*--cdst = *--csrc;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
