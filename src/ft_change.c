/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:48:17 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/28 16:48:19 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		ft_mandelbrot(t_f *f)
{
	int		i;

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
	return (i);
}

int		ft_buffalo(t_f *f)
{
	int		i;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre;
		f->j.oldim = f->j.newim;
		f->j.newre = fabs(f->j.oldre * f->j.oldre -
							f->j.oldim * f->j.oldim) + f->j.cre;
		f->j.newim = fabs(f->j.oldre * f->j.oldim) * (-2) + f->j.cim;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	return (i);
}

int		ft_cubic_mandelbrot(t_f *f)
{
	int		i;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre * f->j.newre;
		f->j.oldim = f->j.newim * f->j.newim;
		f->j.newim = ((3 * f->j.oldre) - f->j.oldim) * f->j.newim + f->j.cim;
		f->j.newre = (f->j.oldre - (f->j.oldim * 3)) * f->j.newre + f->j.cre;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	return (i);
}

int		ft_celtic(t_f *f)
{
	int		i;

	i = -1;
	while (++i < f->j.maxiterations)
	{
		f->j.oldre = f->j.newre * f->j.newre;
		f->j.oldim = f->j.newim * f->j.newim;
		f->j.newim = ((3 * f->j.oldre) - f->j.oldim) * f->j.newim + f->j.cim;
		f->j.newre = fabs((f->j.oldre - (f->j.oldim * 3)) *
														f->j.newre) + f->j.cre;
		if ((f->j.newre * f->j.newre + f->j.newim * f->j.newim) > 4)
			break ;
	}
	return (i);
}
