/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:42:43 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/10 00:04:36 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char		*cdst;
	const char	*csrc;

	cdst = dst;
	csrc = src;
	while (*csrc)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
	}
	*cdst = '\0';
	return (dst);
}
