/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:07:24 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/28 19:07:25 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void					ft_error(int n)
{
	if (n == 1)
		ft_printf("{red}Fractal no selected.{eoc}\n");
	if (n == 2)
		ft_printf("{red}You are trying to select more than two fractals.\n");
	exit(0);
}

static inline void		ft_error_name(void)
{
	ft_printf("{red}Wrong fractal name!!!{eoc}\n");
	ft_printf("{cyan}You can use fractals from the list:\n");
	ft_printf("{yellow}1 -   Julia\n");
	ft_printf("2 -   Celtic\n");
	ft_printf("3 -   Buffalo\n");
	ft_printf("4 -   Vertocal\n");
	ft_printf("5 -   Mandelbrot\n");
	ft_printf("6 -   Burning_ship_5th\n");
	ft_printf("7 -   Cubic_Mandelbrot\n");
	ft_printf("8 -   False_Quasi_Perpendicular_4th\n");
	ft_printf("{red}You can open one or two fractals.{eoc}\n");
	exit(0);
}

void					ft_check_name(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		ft_error(1);
	else if (!ft_strcmp("Mandelbrot", s))
		i++;
	else if (!ft_strcmp("Buffalo", s))
		i++;
	else if (!ft_strcmp("Cubic_Mandelbrot", s))
		i++;
	else if (!ft_strcmp("Celtic", s))
		i++;
	else if (!ft_strcmp("Vertocal", s))
		i++;
	else if (!ft_strcmp("Burning_ship_5th", s))
		i++;
	else if (!ft_strcmp("False_Quasi_Perpendicular_4th", s))
		i++;
	else if (!ft_strcmp("Julia", s))
		i++;
	if (i == 0)
		ft_error_name();
}
