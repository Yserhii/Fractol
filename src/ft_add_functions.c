/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:18:22 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/27 13:18:24 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_change_color(t_f *f)
{
	f->n += 1;
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_stream(f);
}

void	ft_iter_p_m(t_f *f, char c)
{
	if (c == '-' && f->j.maxiterations > 10)
		f->j.maxiterations -= 10;
	else if (c == '+' && f->j.maxiterations < 100000)
		f->j.maxiterations += 10;
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_stream(f);
}

void	ft_move_frac(t_f *f, int keycode)
{
	if (keycode == MOVE_U)
		f->j.movey -= 0.0003;
	else if (keycode == MOVE_D)
		f->j.movey += 0.0003;
	else if (keycode == MOVE_L)
		f->j.movex += 0.0003;
	else if (keycode == MOVE_R)
		f->j.movex -= 0.0003;
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_stream(f);
}

void	ft_shape_frac(t_f *f, int keycode)
{
	if (keycode == SHAPE_U)
		f->j.cim += 0.0002;
	else if (keycode == SHAPE_D)
		f->j.cim -= 0.0002;
	else if (keycode == SHAPE_R)
		f->j.cre += 0.0002;
	else if (keycode == SHAPE_L)
		f->j.cre -= 0.0002;
	f->img->ptr = mlx_new_image(f->img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ft_stream(f);
}
