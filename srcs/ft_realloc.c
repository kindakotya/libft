/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:18:56 by gmayweat          #+#    #+#             */
/*   Updated: 2021/05/18 02:36:29 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_realloc(void *s, size_t size)
{
	void	*meow;
	size_t	i;

	i = 0;
	meow = malloc(size);
	if (!meow)
		return (NULL);
	while (((unsigned char *)s)[i])
	{
		((unsigned char *)meow)[i] = ((unsigned char *)s)[i];
		++i;
	}
	free(s);
	return (meow);
}
