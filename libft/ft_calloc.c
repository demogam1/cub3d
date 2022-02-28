/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:19:47 by misaev            #+#    #+#             */
/*   Updated: 2021/04/06 11:10:27 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*coco;
	size_t	i;
	size_t	total;

	total = num * size;
	coco = malloc(total);
	if (!coco)
		return (NULL);
	i = 0;
	while (total--)
	{
		coco[i] = 0;
		i++;
	}
	return ((void *)coco);
}
