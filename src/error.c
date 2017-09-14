/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:27:46 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:25:18 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	malloc_error(void)
{
	ft_putstr("Could not malloc. Exiting the program.\n");
	exit(1);
}

void	put_error(t_env *a)
{
	ft_putstr("Invalid parameter, exiting the program.\n");
	ft_putstr("Please type only ONE fractal name.\n");
	ft_putstr("Fractals available : mandelbrot, julia, burningship.\n");
	free(a);
	exit(1);
}
