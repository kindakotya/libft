/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:47:26 by gmayweat          #+#    #+#             */
/*   Updated: 2021/04/22 22:40:20 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0 || src == dest)
		return (dest);
	if (dest > src && dest < src + len)
	{
		while (len--)
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		return (dest);
	}
	else
	{
		while (i++ < len)
		{
			*((unsigned char *)dest) = *((unsigned char *)src);
			++dest;
			++src;
		}
	}
	return (dest - len);
}
