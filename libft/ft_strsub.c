/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:25:52 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 18:27:22 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*cstr;

	if (!s || !(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	cstr = str;
	s += start;
	while (len--)
		*cstr++ = *s++;
	*cstr = '\0';
	return (str);
}
