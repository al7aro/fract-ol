/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:05:12 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/21 17:59:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"
#include "utils.h"

int	type(int keycode, t_fract *f)
{
	if (keycode == J)
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
	return (0);
}

int	mouse_type(int button, int x, int y, t_fract *f)
{
	t_vec2		w;
	long double	prev_zoom;

	w = screen_to_world(*f, x, y);
	prev_zoom = f->zoom;
	if (button == MLB && f->type == MANDELBROT)
	{
		f->julia_init = (t_vec2){{f->mouse_pos.x}, {f->mouse_pos.y}};
		f->prev_center = (t_vec2){{f->center.x}, {f->center.y}};
		f->type = JULIA;
		f->prev_zoom = f->zoom;
		f->zoom = MIN_ZOOM;
		f->center = (t_vec2){{0}, {0}};
	}
	else if (button == MRB && f->type == JULIA)
	{
		f->zoom = f->prev_zoom;
		f->type = MANDELBROT;
		f->center = (t_vec2){{f->prev_center.x}, {f->prev_center.y}};
		f->moving_julia = 0;
	}
	update_world(f);
	return (0);
}
