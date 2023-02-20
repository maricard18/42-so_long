/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:35:37 by maricard          #+#    #+#             */
/*   Updated: 2023/02/20 13:51:42 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dot_ber_validation(char *str, int i)
{
	char	*ber_str;
	char	*ber;
	int		flag;

	ber = ".ber";
	ber_str = ft_substr(str, i, 4);
	flag = ft_strncmp(ber, ber_str, 4);
	if (flag == 0)
		return (1);
	else
		return (0);
}

int	extension_validation(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str)
	{
		if (str[i] == '.')
		{
			flag = dot_ber_validation(str, i);
			if (flag == 1)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
