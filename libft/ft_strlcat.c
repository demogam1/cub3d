/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:07:58 by misaev            #+#    #+#             */
/*   Updated: 2021/04/05 11:08:01 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_len;
	size_t	src_dest;

	src_dest = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	i = 0;
	if (destsize <= src_dest || destsize <= 0)
		return (src_len + destsize);
	while (src[i] != '\0' && (src_dest + i) < (destsize - 1))
	{
		dest[src_dest + i] = src[i];
		i++;
	}
	dest[src_dest + i] = '\0';
	return (src_dest + src_len);
}
