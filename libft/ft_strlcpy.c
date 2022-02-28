/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:08:05 by misaev            #+#    #+#             */
/*   Updated: 2021/04/06 14:20:01 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	b;

	b = 0;
	i = 0;
	if (!dest)
		return (0);
	while (src[i])
		i++;
	if (!size)
		return (i);
	while (src[b] && b < size - 1)
	{
		dest[b] = src[b];
		b++;
	}
	dest[b] = '\0';
	return (i);
}
