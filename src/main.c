/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:08:02 by yserhii           #+#    #+#             */
/*   Updated: 2019/03/24 13:08:04 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static inline t_img		*init_img(void)
{
	t_img	*img;

	img = ft_memalloc(sizeof(t_img));
	img->mlx_ptr = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx_ptr, WIN_W,
														WIN_HEIGHT, "FRACTOL");
	img->ptr = mlx_new_image(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
												&img->size_line, &img->endian);
	return (img);
}

static inline void		ft_two_windows(char *str)
{
	char		*tmp;
	pthread_t	stream[1];

	tmp = ft_strdup("./fractol ");
	tmp = ft_strjoin(tmp, str);
	pthread_create(&stream[0], NULL, (void *)system, tmp);
}

int						main(int ac, char **av)
{
	t_f			*f;

	ft_check_name(av[1]);
	if (ac == 3)
		ft_two_windows(av[2]);
	if (ac > 1 && ac < 4)
	{
		f = ft_memalloc(sizeof(t_f));
		f->img = init_img();
		key_init(f);
		ft_menu(f);
		ft_visual(f, av[1]);
		mlx_loop(f->img->mlx_ptr);
	}
	else
		ft_error(2);
	return (0);
}
