/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:15:41 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/21 05:06:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "keycodes.h"
#include "ft_printf.h"
#include "libft.h"
#include "fractol.h"
#include "utils.h"
#include "ft_math.h"
#include "temp.h"
#include "shade.h"

#include <stdio.h>

int	key_pressed(int keycode, void *param)
{
	t_fract	*f;

//	ft_printf("KEY: %d\n", keycode);
	f = (t_fract *)param;
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP || keycode == W)
		f->center.y += 40.0 / f->zoom;
	else if (keycode == DOWN || keycode == S)
		f->center.y -= 40.0 / f->zoom;
	else if (keycode == LEFT || keycode == A)
		f->center.x -= 40.0 / f->zoom;
	else if (keycode == RIGHT || keycode == D)
		f->center.x += 40.0 / f->zoom;
	else if (keycode == PLUS)
		f->it += log10(f->zoom);
	else if (keycode == MINUS)
		f->it -= log10(f->zoom);
	else if (keycode == DEL)
		f->render_factor++;
	else if (keycode == M)
		f->menu_toggle = !f->menu_toggle;
	else if (keycode == C)
		f->ran_sel++;
	else if (keycode == X)
		render_export(f);
	else if (keycode == SPACE)
		f->moving_julia = !f->moving_julia;
	else if (keycode == J)
	{
		if (f->type == MANDELBROT)
		{
			f->moving_julia = 1;
			f->julia_init = (t_vec2){{f->mouse_pos.x}, {f->mouse_pos.y}};
			f->prev_center = (t_vec2){{f->center.x}, {f->center.y}};
			f->type = JULIA;
			f->prev_zoom = f->zoom;
			f->zoom = MIN_ZOOM;
			f->center = (t_vec2){{0}, {0}};
		}
		else if (f->type == JULIA)
		{
			f->moving_julia = 0;
			f->zoom = f->prev_zoom;
			f->type = MANDELBROT;
			f->center = (t_vec2){{f->prev_center.x}, {f->prev_center.y}};
		}
	}
	else if (keycode == INTRO)
		if (f->render_factor > 1)
			f->render_factor--;
	update_world(f);
	return (0);
}

int	mouse_pressed(int button, int x, int y, void *param)
{
	t_fract		*f;
	t_vec2		w;
	long double	prev_zoom;

	f = (t_fract *)param;
	w = screen_to_world(*f, x, y);
	prev_zoom = f->zoom;
	if (button == MSCROLL_DOWN && f->zoom < MAX_ZOOM)
	{
		f->zoom += (f->zoom / f->szoom);
		f->center.x = (w.r - (prev_zoom * (w.r - f->center.x) / f->zoom));
		f->center.y = -(w.i - (prev_zoom * (w.i + f->center.y) / f->zoom));
		update_world(f);
	}
	if (button == MSCROLL_UP && f->zoom > MIN_ZOOM)
	{
		f->zoom -= (f->zoom / f->szoom);
		f->center.x = (w.r - (prev_zoom * (w.r - f->center.x) / f->zoom));
		f->center.y = -(w.i - (prev_zoom * (w.i + f->center.y) / f->zoom));
		update_world(f);
	}
	if (button == MLB && f->type == MANDELBROT)
	{
		f->julia_init = (t_vec2){{f->mouse_pos.x}, {f->mouse_pos.y}};
		f->prev_center = (t_vec2){{f->center.x}, {f->center.y}};
		f->type = JULIA;
		f->prev_zoom = f->zoom;
		f->zoom = MIN_ZOOM;
		f->center = (t_vec2){{0}, {0}};
	}
	if (button == MRB && f->type == JULIA)
	{
		f->zoom = f->prev_zoom;
		f->type = MANDELBROT;
		f->center = (t_vec2){{f->prev_center.x}, {f->prev_center.y}};
		f->moving_julia = 0;
	}
	update_world(f);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_fract	*f;
	t_vec2	c;
	double	temp;
	t_vec2	temp_center;

	f = (t_fract *)param;
	c = screen_to_world(*f, x, y);
	if (f->moving_julia)
	{
		temp = f->zoom; 
		f->zoom = f->prev_zoom;
		temp_center = (t_vec2){{f->center.x}, {f->center.y}};
		f->center = (t_vec2){{f->prev_center.x}, {f->prev_center.y}};
		update_world(f);
		c = screen_to_world(*f, x, y);
		f->julia_init = c;
		f->zoom = temp;
		f->center = (t_vec2){{temp_center.x}, {temp_center.y}};
		update_world(f);
	}
	f->mouse_pos = c;
	return (0);
}
