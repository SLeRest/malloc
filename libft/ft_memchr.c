/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:14:04 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/15 14:47:12 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;

	if (!n)
		return (NULL);
	cs = (unsigned char *)s;
	while (*cs != (unsigned char)c && --n)
		cs++;
	if (*cs == (unsigned char)c)
		return (cs);
	else
		return (NULL);
}
