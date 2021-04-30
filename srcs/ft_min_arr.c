/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:08:21 by gmayweat          #+#    #+#             */
/*   Updated: 2021/04/30 01:09:03 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_min_arr(double *arr, int size)
{
	double	n;
	int		i;

	i = 0;
	n = arr[0];
	while (i < size)
	{
		if (n < arr[i])
			n = arr[i];
		i++;
	}
	return (n);
}
