/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:01:17 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 16:27:45 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cdst;

	cdst = dst;
	while (*src && len)
	{
		*cdst++ = *src++;
		len--;
	}
	while (len)
	{
		*cdst++ = '\0';
		len--;
	}
	return (dst);
}
