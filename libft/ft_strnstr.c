/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:01:05 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 17:44:08 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			clen;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len--)
	{
		j = 0;
		clen = len + 1;
		while (needle[j] && haystack[i + j] &&
				needle[j] == haystack[i + j] && clen)
		{
			if (!needle[j + 1] && clen)
				return ((char *)haystack + i);
			j++;
			clen--;
		}
		i++;
	}
	return (NULL);
}
