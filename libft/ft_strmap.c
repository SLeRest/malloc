/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:46:29 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 18:20:50 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*cstr;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
		return (NULL);
	cstr = str;
	while (*s)
		*cstr++ = f(*s++);
	*cstr = '\0';
	return (str);
}
