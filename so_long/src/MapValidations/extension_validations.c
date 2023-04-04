/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_validations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:35:37 by maricard          #+#    #+#             */
/*   Updated: 2023/04/04 11:49:29 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_validation(t_root *root, char *str)
{
	char	*extension;
	int		i;
	int		a;
	int		c;

	extension = ".ber";
	i = ft_strlen(str) - 4;
	a = ft_strlen(str);
	c = 0;
	while (i < a)
	{
		if (extension[c] != str[i])
			ft_error(root, "Map extension is invalid");
		i++;
		c++;
	}
	return (0);
}
