/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others_frac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:48:30 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/27 17:48:32 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static inline void	ft_print_one_pixel_other(t_coor add, t_f *f)
{
	int i;

	if ((add.x >= 0 && add.x < WIN_WIDTH) && (add.y >= 0 && add.y < WIN_HEIGHT))
	{
		i = (add.y * WIN_WIDTH) + add.x;
		((t_color *)f->img->addr)[i].r = (f->color >> (16 + f->n)) & 0xFF;
		((t_color *)f->img->addr)[i].g = (f->color >> (8 + f->n)) & 0xFF;
		((t_color *)f->img->addr)[i].b = (f->color >> (0 + f->n)) & 0xFF;
		((t_color *)f->img->addr)[i].a = 0;
	}
}

static inline int	ft_choice_frac(t_f *f)
{
	int		i;

	i = 0;
	if (!ft_strcmp("Mandelbrot", f->str))
		i = ft_mandelbrot(f);
	else if (!ft_strcmp("Buffalo", f->str))
		i = ft_buffalo(f);
	else if (!ft_strcmp("Cubic_Mandelbrot", f->str))
		i = ft_cubic_mandelbrot(f);
	else if (!ft_strcmp("Celtic", f->str))
		i = ft_celtic(f);
	else if (!ft_strcmp("Vertocal", f->str))
		i = ft_vertocal(f);
	else if (!ft_strcmp("Burning_ship_5th", f->str))
		i = ft_burning_ship_5th(f);
	else if (!ft_strcmp("False_Quasi_Perpendicular_4th", f->str))
		i = ft_false_quasi_perpendicular_4th(f);
	return (i);
}

static inline void	ft_iter_param_other(t_f *f)
{
	int		i;
	double	t;

	i = ft_choice_frac(f);
	t = (double)(i) / (double)(f->j.maxiterations);
	f->color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
				(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
							(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void				draw_frac(t_f *f)
{
	t_coor	c;

	c.y = -1;
	f->j.zoom_x = (f->j.re_max - f->j.re_min) / WIN_WIDTH;
	f->j.zoom_y = (f->j.im_min - f->j.im_max) / WIN_HEIGHT;
	while (++c.y < WIN_HEIGHT)
	{
		c.x = f->img_first - 1;
		f->j.cim = (c.y * f->j.zoom_y) + f->j.im_max + f->j.movey;
		while (++c.x < f->img_last)
		{
			f->j.cre = (c.x * f->j.zoom_x) + f->j.re_min + f->j.movex;
			f->j.newre = 0;
			f->j.newim = 0;
			f->j.oldre = 0;
			f->j.oldim = 0;
			ft_iter_param_other(f);
			ft_print_one_pixel_other(c, f);
		}
	}
}
