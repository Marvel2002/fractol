/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:28:35 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:16:30 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_zoom_hook(int button, int x, int y, t_env *a)
{
	if (button == 7)
	{
		a->x -= x / 5;
		a->y -= y / 5;
		a->zoom = a->zoom / 1.2;
		a->y = a->y / 1.2;
		a->x = a->x / 1.2;
	}
	if (button == 6)
	{
		a->x += x / 5;
		a->y += y / 5;
		a->zoom = a->zoom * 1.2;
		a->y = a->y * 1.2;
		a->x = a->x * 1.2;
	}
	a->fractal(a);
	return (0);
}

int		fractal_param(int x, int y, t_env *a)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT && a->trigger == 1)
	{
		a->div_width = 0.007 * (x - (WIDTH / 2));
		a->div_height = 0.010 * (y - (HEIGHT / 2));
		a->fractal(a);
	}
	return (0);
}
