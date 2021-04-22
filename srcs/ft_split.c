/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:59:16 by gmayweat          #+#    #+#             */
/*   Updated: 2021/04/23 01:22:50 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findwords(const char *s, char c)
{
	int	i;
	int	nwords;

	i = 0;
	nwords = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++nwords;
			while (s[i] != c && s[i])
				++i;
			if (!s[i])
				return (nwords);
		}
		++i;
	}
	return (nwords);
}

static void	*ft_free(char **arr, int k)
{
	while (k > 0)
		free(arr[k--]);
	if (arr[0] != NULL)
		free(arr[0]);
	free(arr);
	return (NULL);
}

static void	ft_wordcpy(char *arr, const char *s, int tekp, int end)
{
	int	l;

	l = 0;
	while (tekp < end)
		arr[l++] = s[tekp++];
	arr[l] = '\0';
}

int	ft_love_norme(char **arr, const char *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i])
				++i;
			arr[k++] = (char *)malloc((i - j + 1) * sizeof(char));
			if (!arr[k - 1])
				return (k - 1);
			ft_wordcpy(arr[k - 1], s, j, i);
		}
		if (s[i])
			++i;
	}
	arr[k] = NULL;
	return (-1);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		meow;

	if (!s)
		return (NULL);
	arr = malloc((ft_findwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	meow = ft_love_norme(arr, s, c);
	if (meow != -1)
		return (ft_free(arr, meow));
	return (arr);
}
