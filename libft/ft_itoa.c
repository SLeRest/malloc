/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:06:16 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/12 17:40:49 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_max_and_zero(int n)
{
	if (n == -2147483648)
		return ("-2147483648");
	else if (!n)
		return ("0");
	else
		return (NULL);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		cn;
	int		len;

	if (ft_max_and_zero(n))
		return (ft_strdup(ft_max_and_zero(n)));
	else
	{
		cn = (n < 0) ? -n : n;
		len = (n < 0) ? 3 : 2;
		while (cn /= 10)
			len++;
		if (!(s = (char *)malloc(sizeof(*s) * len)))
			return (NULL);
		s[--len] = '\0';
		cn = (n < 0) ? -n : n;
		while (cn)
		{
			s[--len] = cn % 10 + '0';
			cn /= 10;
		}
		if (n < 0)
			s[0] = '-';
	}
	return (s);
}
