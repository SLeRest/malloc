/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-rest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:32:43 by sle-rest          #+#    #+#             */
/*   Updated: 2017/11/10 15:41:25 by sle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cs;

	cs = (char *)s;
	while (*cs)
		cs++;
	while (*cs != (char)c && cs > s)
		cs--;
	if (cs == s && *cs != (char)c)
		return (NULL);
	else
		return (cs);
}
