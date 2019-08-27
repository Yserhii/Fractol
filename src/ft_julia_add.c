/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:57:59 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/26 17:58:00 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static inline int	ft_digit(int old, int new)
{
	if (old < new)
		return (1);
	else if (old > new)
		return (-1);
	return (0);
}

int					ft_mouse_julia(int x, int y, t_f *f)
{
	int			new_x;
	int			new_y;
	static int	old_x = 0;
	static int	old_y = 0;

	new_x = ft_digit(old_x, x);
	new_y = ft_digit(old_y, y);
	f->j.cre += new_x * (x - WIN_WIDTH / 2.5) / (WIN_WIDTH / 0.0025) * 10;
	f->j.cim += new_y * (y - WIN_HEIGHT / 2.5) / (WIN_WIDTH / 0.0025) * 10;
	old_x = x;
	old_y = y;
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_stream(f);
	return (0);
}

static inline void	ft_interpol(t_f *f, double re, double im, double iter)
{
	f->j.re_min = (re + ((f->j.re_min - re)) * iter);
	f->j.im_min = (im + ((f->j.im_min - im)) * iter);
	f->j.re_max = (re + ((f->j.re_max - re)) * iter);
	f->j.im_max = (im + ((f->j.im_max - im)) * iter);
}

int					mouse(int keycode, int x, int y, t_f *f)
{
	double	mousere;
	double	mouseim;
	double	mousemaxiterations;

	y = WIN_HEIGHT - y;
	if (keycode == ZOOM_M)
	{
		mousemaxiterations = (f->julia == 1 ? (1.0 / 1.1) : (1.0 * 1.1));
		mousere = x / (WIN_WIDTH / (f->j.re_max - f->j.re_min)) + f->j.re_min;
		mouseim = y / (WIN_HEIGHT / (f->j.im_max - f->j.im_min)) + f->j.im_min;
		ft_interpol(f, mousere, mouseim, mousemaxiterations);
	}
	else if (keycode == ZOOM_P)
	{
		mousemaxiterations = (f->julia == 1 ? (1.0 * 1.1) : (1.0 / 1.1));
		mousere = x / (WIN_WIDTH / (f->j.re_max - f->j.re_min)) + f->j.re_min;
		mouseim = y / (WIN_HEIGHT / (f->j.im_max - f->j.im_min)) + f->j.im_min;
		ft_interpol(f, mousere, mouseim, mousemaxiterations);
	}
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_stream(f);
	return (0);
}
