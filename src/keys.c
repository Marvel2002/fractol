/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:28:19 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:18:46 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_zoom(int keycode, t_env *a)
{
	if (keycode == PLUS)
	{
		a->x += WIDTH / 12;
		a->y += HEIGHT / 12;
		a->zoom = a->zoom * 1.2;
		a->x = a->x * 1.2;
		a->y = a->y * 1.2;
		a->fractal(a);
	}
	if (keycode == MINUS)
	{
		if (a->zoom / 1.2 < 10)
			return ;
		a->x -= WIDTH / 12;
		a->y -= HEIGHT / 12;
		a->zoom = a->zoom / 1.2;
		a->x = a->x / 1.2;
		a->y = a->y / 1.2;
		a->fractal(a);
	}
}

void	key_iter(int keycode, t_env *a)
{
	if (keycode == DIVIDE)
	{
		a->iteration_max -= 5;
		a->fractal(a);
	}
	if (keycode == MULTIPLY)
	{
		a->iteration_max += 5;
		a->fractal(a);
	}
}

void	key_move(int keycode, t_env *a)
{
	if (keycode == DOWN)
	{
		a->y += 100;
		a->fractal(a);
	}
	if (keycode == UP)
	{
		a->y -= 100;
		a->fractal(a);
	}
	if (keycode == LEFT)
	{
		a->x -= 100;
		a->fractal(a);
	}
	if (keycode == RIGHT)
	{
		a->x += 100;
		a->fractal(a);
	}
}

void	key_utils(int keycode, t_env *a)
{
	if (keycode == A)
		a->trigger = 0;
	if (keycode == S)
		a->trigger = 1;
	if (keycode == C)
	{
		a->color++;
		if (a->color == 3)
			a->color = 0;
		a->fractal(a);
	}
	if (keycode == R)
	{
		init_env(a);
		a->fractal(a);
	}
}

int		key_hook(int keycode, t_env *a)
{
	if (keycode == ESCAPE)
	{
		free(a);
		exit(1);
	}
	key_zoom(keycode, a);
	key_iter(keycode, a);
	key_move(keycode, a);
	key_utils(keycode, a);
	return (0);
}
