/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:30:03 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/24 13:30:04 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static inline int		x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static inline void		ft_bzero_frac(t_f *f)
{
	free(f->str);
	f->n = 0;
	f->j.cre = 0;
	f->j.cim = 0;
	f->julia = 0;
	f->color = 0;
	f->j.movex = 0;
	f->j.movey = 0;
	f->j.newre = 0;
	f->j.newim = 0;
	f->j.oldre = 0;
	f->j.oldim = 0;
	f->j.zoom_x = 0;
	f->j.zoom_y = 0;
	f->j.im_min = 0;
	f->j.im_max = 0;
	f->j.re_min = 0;
	f->j.re_max = 0;
	f->img_last = 0;
	f->img_first = 0;
	f->j.maxiterations = 0;
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
}

static inline void		ft_change_frac(int keycode, t_f *f)
{
	ft_bzero_frac(f);
	if (keycode == JULIA)
		ft_visual(f, "Julia");
	else if (keycode == CELTIC)
		ft_visual(f, "Celtic");
	else if (keycode == BUFFALO)
		ft_visual(f, "Buffalo");
	else if (keycode == VERTOCAL)
		ft_visual(f, "Vertocal");
	else if (keycode == MANDELBROT)
		ft_visual(f, "Mandelbrot");
	else if (keycode == BURNING)
		ft_visual(f, "Burning_ship_5th");
	else if (keycode == CUBIC)
		ft_visual(f, "Cubic_Mandelbrot");
	else if (keycode == QUASI)
		ft_visual(f, "False_Quasi_Perpendicular_4th");
}

static int				key(int keycode, t_f *f)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == ITER_M)
		ft_iter_p_m(f, '-');
	else if (keycode == ITER_P)
		ft_iter_p_m(f, '+');
	else if (keycode == MOVE_U || keycode == MOVE_D ||
								keycode == MOVE_R || keycode == MOVE_L)
		ft_move_frac(f, keycode);
	else if (keycode == SHAPE_U || keycode == SHAPE_D ||
								keycode == SHAPE_R || keycode == SHAPE_L)
		ft_shape_frac(f, keycode);
	else if (keycode == JULIA || keycode == CELTIC || keycode == BUFFALO
		|| keycode == VERTOCAL || keycode == MANDELBROT || keycode == BURNING
									|| keycode == CUBIC || keycode == QUASI)
		ft_change_frac(keycode, f);
	else if (keycode == COLOR)
		ft_change_color(f);
	return (0);
}

void					key_init(t_f *f)
{
	mlx_hook(f->img->mlx_win, 2, X_MASK, key, f);
	mlx_hook(f->img->mlx_win, 4, X_MASK, mouse, f);
	mlx_hook(f->img->mlx_win, 17, X_MASK, x, f);
}
