/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:38:04 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/10 15:42:23 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*chaystack;
	char	*cneedle;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	chaystack = (char *)haystack;
	cneedle = (char *)needle;
	i = 0;
	while (chaystack[i])
	{
		j = 0;
		while (chaystack[i + j] == cneedle[j] && chaystack[i + j] && cneedle[j])
		{
			if (chaystack[i + j] == cneedle[j] && cneedle[j + 1] == '\0')
				return (chaystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
