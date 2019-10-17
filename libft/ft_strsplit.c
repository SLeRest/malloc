/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:52:35 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 21:48:44 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_w(char const *s, char c)
{
	size_t	count;

	count = (*s == c) ? 0 : 1;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			while (*s == c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static size_t	ft_count_c(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != c && *s)
	{
		s++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	*cs;
	char	**tab;

	if (!s || !(tab = (char **)malloc(sizeof(*tab) * (ft_count_w(s, c) + 1))))
		return (NULL);
	cs = (char *)s;
	while (*cs == c && *cs)
		cs++;
	i = 0;
	while (*cs)
	{
		if (!(tab[i] = (char *)malloc(sizeof(**tab) * (ft_count_c(cs, c) + 1))))
			return (NULL);
		j = 0;
		while (*cs != c && *cs)
			tab[i][j++] = *cs++;
		tab[i++][j] = '\0';
		while (*cs == c && *cs)
			cs++;
	}
	tab[i] = 0;
	return (tab);
}
