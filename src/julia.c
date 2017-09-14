/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:28:12 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:18:02 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_env *a)
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
			a->zr = x / a->zoom + a->x1;
			a->zi = y / a->zoom + a->y1;
			a->cr = a->div_width;
			a->ci = a->div_height;
			a->i = 0;
			mandel_iter(a, x, y);
		}
	}
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}
