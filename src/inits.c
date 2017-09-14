/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:28:03 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:16:16 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_env(t_env *a)
{
	a->x = 0;
	a->y = 0;
	a->trigger = 0;
	a->trigger_zoom = 0;
	a->div_width = 0;
	a->div_height = 0;
	a->color = 0;
	a->zoom = 150;
	a->iteration_max = 50;
	if (a->fractal == burningship)
		a->iteration_max = 25;
}

void	mdb_init(t_env *a)
{
	a->zr = 0;
	a->zi = 0;
	a->cr = 0;
	a->ci = 0;
	a->tmp = 0;
	a->x1 = -2.1;
	a->x2 = 0.6;
	a->y1 = -1.2;
	a->y2 = 1.2;
}

int		fractal_init(t_env *a, char *str)
{
	if (!ft_strcmp("mandelbrot", str))
	{
		a->fractal = mandelbrot;
		mdb_init(a);
		return (1);
	}
	if (!ft_strcmp("julia", str))
	{
		a->fractal = julia;
		mdb_init(a);
		return (1);
	}
	if (!ft_strcmp("burningship", str))
	{
		a->fractal = burningship;
		mdb_init(a);
		return (1);
	}
	return (0);
}
