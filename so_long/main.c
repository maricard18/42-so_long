/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:40:25 by maricard          #+#    #+#             */
/*   Updated: 2023/02/20 12:25:09 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Program needs a map.ber to start!");
		return (0);
	}
	if (extension_validation(argv[1]) != 1)
	{
		ft_printf("Please verify that you have a .ber extension!");
		return (0);
	}
	else
		ft_printf("Good job!");

//	map_array_validations(argv[1]);
}
