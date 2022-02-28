/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:50:43 by misaev            #+#    #+#             */
/*   Updated: 2021/04/06 09:20:21 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sour;
	size_t			i;

	i = 0;
	dst = (unsigned char *) dest;
	sour = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (dst > sour)
	{
		while (i < n)
		{
			dst[n - 1] = sour[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		dst[i] = sour[i];
		i++;
	}
	return (dst);
}
