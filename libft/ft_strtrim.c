/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:44:35 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 19:06:14 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhitespace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

static size_t	ft_strlentrim(char const *s)
{
	size_t	trim;

	trim = 0;
	while (ft_iswhitespace(*s) && *s++)
		trim++;
	if (!*s)
		return (trim);
	while (*s)
		s++;
	while (ft_iswhitespace(*--s))
		trim++;
	return (trim);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	char	*cstr;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - ft_strlentrim(s);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (ft_iswhitespace(*s) && *s)
		s++;
	cstr = str;
	while (len--)
		*cstr++ = *s++;
	*cstr = '\0';
	return (str);
}
