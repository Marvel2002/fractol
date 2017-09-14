/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:28:28 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:18:48 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandel_iter(t_env *a, long double x, long double y)
{
	while (a->zr * a->zr + a->zi * a->zi < 4 && a->i++ < a->iteration_max)
	{
		a->tmp = a->zr;
		a->zr = a->zr * a->zr - a->zi * a->zi + a->cr;
		a->zi = 2 * a->zi * a->tmp + a->ci;
		if (a->i == a->iteration_max)
			fill_pixel(a, x - a->x, y - a->y, "black");
		if (a->i >= 0 && a->i <= 14 && a->color == 0)
			fill_pixel(a, x - a->x, y - a->y, "red");
		if (a->i >= 0 && a->i <= 14 && a->color == 1)
			fill_pixel(a, x - a->x, y - a->y, "green");
		if (a->i >= 0 && a->i <= 14 && a->color == 2)
			fill_pixel(a, x - a->x, y - a->y, "blue");
	}
}

void	mandelbrot(t_env *a)
{
	long double x;
	long double y;

	y = a->y;
	ft_bzero(a->data, (HEIGHT * WIDTH) * 4);
	while (++y < HEIGHT + a->y)
	{
		x = a->x;
		while (++x < WIDTH + a->x)
		{
			a->cr = x / a->zoom + a->x1;
			a->ci = y / a->zoom + a->y1;
			a->zr = a->div_width;
			a->zi = a->div_height;
			a->i = 0;
			mandel_iter(a, x, y);
		}
	}
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}
