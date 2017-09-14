/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:28:44 by mmatime           #+#    #+#             */
/*   Updated: 2017/09/14 19:15:29 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 400

# define PLUS 69
# define MINUS 78
# define MULTIPLY 67
# define DIVIDE 75
# define DOWN 125
# define UP 126
# define LEFT 123
# define RIGHT 124
# define S 1
# define A 0
# define C 8
# define R 15
# define ESCAPE 53

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endien;
	int			blue;
	int			red;
	int			green;
	double		x;
	double		y;
	double		zoom;
	int			iteration_max;
	int			trigger;
	int			trigger_zoom;
	int			i;
	int			color;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		tmp;
	double		div_height;
	double		div_width;
	void		(*fractal)();
}				t_env;

void			apply_color(t_env *a, char *str);
void			fill_pixel(t_env *a, int x, int y, char *str);
void			mandel_iter(t_env *a, long double x, long double y);
void			mandelbrot(t_env *a);
void			julia(t_env *a);
void			burning_iter(t_env *a, long double x, long double y);
void			burningship(t_env *a);
void			key_zoom(int keycode, t_env *a);
void			key_iter(int keycode, t_env *a);
void			key_move(int keycode, t_env *a);
void			key_utils(int keycode, t_env *a);
int				key_hook(int keycode, t_env *a);
void			init_env(t_env *a);
int				fractal_param(int x, int y, t_env *a);
int				mouse_zoom_hook(int button, int x, int y, t_env *a);
void			mdb_init(t_env *a);
void			malloc_error(void);
void			print_control(void);
int				fractal_init(t_env *a, char *str);
void			put_error(t_env *a);
int				expose(t_env *a);

#endif
