/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:59:55 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/25 17:59:56 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void				ft_menu(t_f *f)
{
	void	*p;
	void	*w;
	int		c;

	p = f->img->mlx_ptr;
	w = f->img->mlx_win;
	c = 0xFFFFFF;
	mlx_string_put(p, w, 810, 10, c, "Change Fractols:");
	mlx_string_put(p, w, 810, 30, c, "1 - Julia");
	mlx_string_put(p, w, 810, 50, c, "2 - Celtic");
	mlx_string_put(p, w, 810, 70, c, "3 - Buffalo");
	mlx_string_put(p, w, 810, 90, c, "3 - Vertocal");
	mlx_string_put(p, w, 810, 110, c, "5 - Mandelbrot");
	mlx_string_put(p, w, 810, 130, c, "6 - Burning_ship_5th");
	mlx_string_put(p, w, 810, 150, c, "7 - Cubic_Mandelbrot");
	mlx_string_put(p, w, 810, 170, c, "8 - False_Quasi_Perpendicular_4th");
	mlx_string_put(p, w, 810, 210, c, "Control:");
	mlx_string_put(p, w, 810, 230, c, "Move up = 8(num)");
	mlx_string_put(p, w, 810, 250, c, "Move down = 5(num)");
	mlx_string_put(p, w, 810, 270, c, "Move right = 6(num)");
	mlx_string_put(p, w, 810, 290, c, "Move left = 4(num)");
	mlx_string_put(p, w, 810, 310, c, "Zoom = scroll down, scroll up");
	mlx_string_put(p, w, 810, 330, c, "Change color = 0");
}

static inline void	draw(t_f *f)
{
	if (!ft_strcmp(f->str, "Julia"))
		draw_j(f);
	else
		draw_frac(f);
}

void				ft_stream(t_f *f)
{
	pthread_t	streams[STREAMS];
	t_f			fs[STREAMS];
	int			i;
	int			x;

	x = 0;
	i = -1;
	while (++i < STREAMS)
	{
		fs[i] = *f;
		fs[i].img_first = x;
		x += (WIN_WIDTH / STREAMS);
		fs[i].img_last = x;
		pthread_create(&streams[i], NULL, (void *)draw, (void *)&fs[i]);
	}
	i = -1;
	while (++i < STREAMS)
		pthread_join(streams[i], NULL);
	mlx_put_image_to_window(f->img->mlx_ptr,
					f->img->mlx_win, f->img->ptr, 0, 0);
	mlx_destroy_image(f->img->mlx_ptr, f->img->ptr);
}
