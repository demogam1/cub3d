/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:46:11 by misaev            #+#    #+#             */
/*   Updated: 2022/01/28 12:24:18 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub.h"

void	print_error(char **texture, char **tab)
{
	free_tab(tab);
	free_tab(texture);
	ft_putstr_fd("Invalid content\n", STDERR_FILENO);
	exit(0);
}

int	extension_parsing_126(int i, char **texture)
{
	free_tab(texture);
	return (i);
}

char	**return_tab_texture(void)
{
	int		i;
	char	**tab;
	char	*texture;

	tab = NULL;
	i = 0;
	texture = (char *)"NO ,SO ,WE ,EA ,F ,C ";
	tab = ft_split((char *)texture, ',');
	return (tab);
}

/* Check if the 6 mandatory elements are available */
int	check_char_content(char *str, char *srch)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	if (str == NULL || srch == NULL)
		return (0);
	len = ft_strlen(srch);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == srch[j] && i == 0)
		{
			while (str[i] == srch[j])
			{
				j++;
				i++;
			}
		}
		if (j == len)
			return (1);
		i++;
	}
	return (0);
}
