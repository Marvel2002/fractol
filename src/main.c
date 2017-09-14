/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:46:42 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:16:24 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_env	*a;

	a = malloc(sizeof(*a));
	if (!a)
		malloc_error();
	if (argc != 2 || !fractal_init(a, argv[1]))
		put_error(a);
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "fract'ol 42");
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->size_line, &a->endien);
	init_env(a);
	a->fractal(a);
	mlx_hook(a->win, 6, 1, fractal_param, a);
	mlx_hook(a->win, 4, 1, mouse_zoom_hook, a);
	mlx_hook(a->win, 2, 1, key_hook, a);
	mlx_hook(a->win, 12, 1, expose, a);
	print_control();
	mlx_loop(a->mlx);
	return (0);
}
