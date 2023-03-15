/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_validations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:35:37 by maricard          #+#    #+#             */
/*   Updated: 2023/03/14 12:25:18 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_validation(char *str, int i)
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
			flag = ber_validation(str, i);
			if (flag == 1)
				return (0);
			else
				ft_error("Map extension is invalid!");
		}
		i++;
	}
	ft_error("Map extension not found.");
	return (0);
}
