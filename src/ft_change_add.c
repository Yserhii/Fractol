/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:50:38 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/28 18:50:48 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		ft_vertocal(t_f *f)
{
	int		i;
	double	re;
	double	im;
	double	ir;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre * f->j.newre;
		f->j.oldim = f->j.newim * f->j.newim;
		re = f->j.oldre * f->j.oldre;
		im = f->j.oldim * f->j.oldim;
		ir = f->j.oldim * f->j.oldre;
		f->j.newim = -f->j.newim * (5 * re - 10 * ir + im) + f->j.cim;
		f->j.newre = f->j.newre * (re - 10 * ir + 5 * im) + f->j.cre;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	return (i);
}

int		ft_burning_ship_5th(t_f *f)
{
	int		i;
	double	re;
	double	im;
	double	ir;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre * f->j.newre;
		f->j.oldim = f->j.newim * f->j.newim;
		re = f->j.oldre * f->j.oldre;
		im = f->j.oldim * f->j.oldim;
		ir = f->j.oldim * f->j.oldre;
		f->j.newim = fabs(f->j.newim) * (5 * re - 10 * ir + im) + f->j.cim;
		f->j.newre = fabs(f->j.newre) * (re - 10 * ir + 5 * im) + f->j.cre;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	return (i);
}

int		ft_false_quasi_perpendicular_4th(t_f *f)
{
	int		i;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre * f->j.newre;
		f->j.oldim = f->j.newim * f->j.newim;
		f->j.newim = -4 * fabs(f->j.newre) * (f->j.newim) *
									fabs(f->j.oldre - f->j.oldim) + f->j.cim;
		f->j.newre = f->j.oldre * f->j.oldre + f->j.oldim *
							f->j.oldim - 6 * f->j.oldre * f->j.oldim + f->j.cre;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	return (i);
}
