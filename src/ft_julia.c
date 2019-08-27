/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:43:43 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/26 14:43:45 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static inline void	ft_print_one_pixel(t_coor add, t_f *f)
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

static inline void	ft_iter_param_julia(t_f *f)
{
	int		i;
	double	t;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre;
		f->j.oldim = f->j.newim;
		f->j.newre = f->j.oldre * f->j.oldre -
							f->j.oldim * f->j.oldim + f->j.cre;
		f->j.newim = 2 * f->j.oldre * f->j.oldim + f->j.cim;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	t = (double)(i) / (double)(f->j.maxiterations);
	f->color = (((int)((9 * (1 - t) * t * t * t * 255)) << 16) |
				(((int)(15 * (1 - t) * (1 - t) * t * t * 255)) << 8)) |
							(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void				draw_j(t_f *f)
{
	t_coor	c;

	c.y = -1;
	f->j.zoom_x = (f->j.re_max - f->j.re_min);
	f->j.zoom_y = (f->j.im_min - f->j.im_max);
	while (++c.y < WIN_HEIGHT)
	{
		c.x = f->img_first - 1;
		while (++c.x < f->img_last)
		{
			f->j.newre = 1.5 * (c.x - WIN_WIDTH / 2) /
							(0.5 * f->j.zoom_x * WIN_WIDTH) + f->j.movex;
			f->j.newim = (c.y - WIN_HEIGHT / 2) /
							(0.5 * f->j.zoom_y * WIN_HEIGHT) + f->j.movey;
			ft_iter_param_julia(f);
			ft_print_one_pixel(c, f);
		}
	}
}
