/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:08:34 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/24 13:08:36 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define X_MASK 0
# define STREAMS 8
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define WIN_W 1200

# define ESC 53
# define ZOOM_P 4
# define ZOOM_M 5
# define ITER_P 69
# define ITER_M 78
# define MOVE_U 91
# define MOVE_D 87
# define MOVE_L 86
# define MOVE_R 88
# define SHAPE_U 126
# define SHAPE_D 125
# define SHAPE_L 123
# define SHAPE_R 124
# define JULIA 18
# define CUBIC 26
# define QUASI 28
# define CELTIC 19
# define BURNING 22
# define BUFFALO 20
# define VERTOCAL 21
# define MANDELBROT 23
# define COLOR 29

# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <pthread.h>

typedef	struct		s_img
{
	int				bpp;
	int				size_line;
	int				endian;
	char			*addr;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*ptr;

}					t_img;

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef	struct		s_coor
{
	int				color;
	double			x;
	double			y;
}					t_coor;

typedef	struct		s_j
{
	int		maxiterations;
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	zoom_x;
	double	zoom_y;
	double	movex;
	double	movey;
	double	im_min;
	double	im_max;
	double	re_min;
	double	re_max;
}					t_j;

typedef	struct		s_f
{
	t_j				j;
	t_j				m;
	t_img			*img;
	int				n;
	int				color;
	int				img_first;
	int				img_last;
	int				julia;
	char			*str;
}					t_f;

void				draw_j(t_f *f);
void				ft_error(int n);
void				key_init(t_f *f);
void				ft_stream(t_f *f);
void				draw_frac(t_f *f);
void				ft_iter_p_m(t_f *f, char c);
void				ft_visual(t_f *f, char *str);
void				ft_move_frac(t_f *f, int keycode);
void				ft_shape_frac(t_f *f, int keycode);
int					ft_mouse_julia(int x, int y, t_f *f);
int					mouse(int keycode, int x, int y, t_f *f);
int					ft_mandelbrot(t_f *f);
int					ft_buffalo(t_f *f);
int					ft_cubic_mandelbrot(t_f *f);
int					ft_celtic(t_f *f);
int					ft_vertocal(t_f *f);
int					ft_burning_ship_5th(t_f *f);
int					ft_false_quasi_perpendicular_4th(t_f *f);
void				ft_check_name(char *s);
void				ft_menu(t_f *f);
void				ft_change_color(t_f *f);

#endif
