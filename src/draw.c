/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:27:30 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:18:30 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	apply_color(t_env *a, char *str)
{
	if (!ft_strcmp(str, "black"))
	{
		a->red = 0;
		a->green = 0;
		a->blue = 0;
	}
	else if (!ft_strcmp(str, "red"))
	{
		a->red = 17 * a->i;
		a->green = 0;
		a->blue = 0;
	}
	else if (!ft_strcmp(str, "green"))
	{
		a->red = 0;
		a->green = 17 * a->i;
		a->blue = 0;
	}
	else if (!ft_strcmp(str, "blue"))
	{
		a->red = 0;
		a->green = 0;
		a->blue = 17 * a->i;
	}
}

void	fill_pixel(t_env *a, int x, int y, char *str)
{
	int i;
	int j;

	i = 0 + (4 * x);
	j = i + (a->size_line * y);
	apply_color(a, str);
	a->data[j] = a->blue;
	a->data[j + 1] = a->green;
	a->data[j + 2] = a->red;
}

void	print_control(void)
{
	ft_putendl("\n |    Move : up down left right                |\n");
	ft_putendl(" |    Mouse ON : 's'  Mouse OFF : 'a'          |\n");
	ft_putendl(" |    Zoom In '+'  Zoom Out '-'                |\n");
	ft_putendl(" |    Iteration Up '*'  Iteration Down '/'     |\n");
	ft_putendl(" |    Switch color 'c'                         |\n");
}
