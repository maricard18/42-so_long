/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:38:55 by maricard          #+#    #+#             */
/*   Updated: 2023/03/29 12:58:40 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_root *root, char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	destroy(root);
	exit(1);
}
