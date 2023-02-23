/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:40:25 by maricard          #+#    #+#             */
/*   Updated: 2023/02/23 10:30:49 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Program needs a map.ber to start!");
		return (0);
	}
	if (extension_validation(argv[1]) != 1)
	{
		ft_printf("Invalid .ber extension");
		return (0);
	}
	else
		ft_printf("Good job!");
	map_array_validations(argv[1]);

//	map_array_validations(argv[1]);
}
