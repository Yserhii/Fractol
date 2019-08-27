/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:20:17 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/24 13:20:18 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static inline void	ft_param_julia(t_f *f)
{
	f->j.re_max = 1;
	f->j.im_max = 1;
	f->j.cre = -0.7;
	f->j.cim = 0.27015;
	f->j.maxiterations = 50;
}

static inline void	ft_param_other(t_f *f)
{
	f->j.re_max = 1;
	f->j.im_max = 2;
	f->j.re_min = -2.2;
	f->j.im_min = -2;
	f->j.maxiterations = 50;
	f->n = 0;
}

void				ft_visual(t_f *f, char *str)
{
	if (!ft_strcmp("Julia", str))
	{
		f->julia = 1;
		ft_param_julia(f);
		mlx_hook(f->img->mlx_win, 6, X_MASK, ft_mouse_julia, f);
	}
	else
		ft_param_other(f);
	f->str = ft_strdup(str);
	ft_stream(f);
}
