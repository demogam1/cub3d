/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:37:47 by misaev            #+#    #+#             */
/*   Updated: 2021/04/06 09:22:54 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *frst, const char *sec, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	while (frst[i] == sec[i] && frst[i]
		!= '\0' && sec[i] != '\0' && i < len - 1)
		i++;
	return ((unsigned char)frst[i] - (unsigned char)sec[i]);
}
