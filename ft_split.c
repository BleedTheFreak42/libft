/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaya <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:24:28 by ytaya             #+#    #+#             */
/*   Updated: 2021/11/06 19:48:19 by ytaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnwords(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n++;
			while (s[i + 1] && s[i + 1] != c)
				i++;
		}
		i++;
	}
	return (n);
}

static int	ft_getwordsize(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strucpy(char const *s, char c)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *) malloc(sizeof(char) * ft_getwordsize(s, c));
	if (!dest)
		return (0);
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	*from;
	int		i;
	int		j;
	char	**table;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	table = (char **) malloc((sizeof(char *) * ft_getnwords(s, c)) + 1);
	if (!table)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			from = (char *) &s[i];
			while (s[i + 1] && s[i + 1] != c)
				i++;
			table[j++] = ft_strucpy(from, c);
		}
		i++;
	}
	table[j] = 0;
	return (table);
}
