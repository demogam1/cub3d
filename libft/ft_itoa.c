/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:11:32 by misaev            #+#    #+#             */
/*   Updated: 2021/04/06 14:36:29 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_putnbr(int nb)
{
	int	nbr;

	nbr = nb;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		return (nbr % 10 + '0');
	}
	if (nbr <= 9)
		return (nbr + '0');
	return (0);
}

static int	len_nbr(int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (i + 1);
	if (c < 0)
	{
		c = c * -1;
		i++;
	}
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

static void	filnewchar(int nbr, char *new, int i)
{
	while (nbr > 0)
	{
		new[i] = ft_putnbr(nbr);
		nbr = nbr / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		p;
	int		nbr;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr = n;
	i = len_nbr(nbr);
	p = 0;
	new = malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	if (nbr < 0)
	{
		new[0] = '-';
		nbr = nbr * -1;
		p++;
	}
	new[i] = '\0';
	i--;
	if (nbr == 0)
		new[i] = '0';
	filnewchar(nbr, new, i);
	return (new);
}
