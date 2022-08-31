/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:03:01 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 16:18:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"
#include "shade.h"
#include "utils.h"
#include "render.h"

int	exponent(int keycode, t_fract *f)
{
	if (keycode == N1)
		f->exp--;
	if (keycode == N2)
		f->exp++;
	if (f->exp < 2)
		f->exp = 2;
	return (0);
}

int	visual(int keycode, t_fract *f)
{
	if (keycode == C)
		f->ran_sel++;
	else if (keycode == F)
		f->func_sel++;
	else if (keycode == X)
		render_export(f);
	else if (keycode == Q)
		f->zoom += (f->zoom / f->szoom);
	else if (keycode == E)
		f->zoom -= (f->zoom / f->szoom);
	else if (keycode == SPACE)
		f->moving_julia = !f->moving_julia;
	else if (keycode == INTRO)
	{
		if (f->render_factor > 1)
			f->render_factor--;
	}
	else
		exponent(keycode, f);
	return (0);
}

int	mouse_move(int x, int y, t_fract *f)
{
	t_vec2	c;
	double	temp_zoom;
	t_vec2	temp_center;

	if (f->moving_julia)
	{
		temp_zoom = f->zoom;
		f->zoom = f->prev_zoom;
		temp_center = (t_vec2){{f->center.x}, {f->center.y}};
		f->center = (t_vec2){{f->prev_center.x}, {f->prev_center.y}};
		update_world(f);
		c = screen_to_world(*f, x, y);
		f->julia_init = c;
		f->zoom = temp_zoom;
		f->center = (t_vec2){{temp_center.x}, {temp_center.y}};
		update_world(f);
	}
	else
		c = screen_to_world(*f, x, y);
	f->mouse_pos = c;
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_fract *f)
{
	t_vec2		w;
	long double	prev_zoom;

	w = screen_to_world(*f, x, y);
	prev_zoom = f->zoom;
	if (button == MSCROLL_DOWN && f->zoom < MAX_ZOOM)
	{
		f->zoom += (f->zoom / f->szoom);
		f->center.x = (w.r - (prev_zoom * (w.r - f->center.x) / f->zoom));
		f->center.y = -(w.i - (prev_zoom * (w.i + f->center.y) / f->zoom));
	}
	else if (button == MSCROLL_UP && f->zoom > MIN_ZOOM)
	{
		f->zoom -= (f->zoom / f->szoom);
		f->center.x = (w.r - (prev_zoom * (w.r - f->center.x) / f->zoom));
		f->center.y = -(w.i - (prev_zoom * (w.i + f->center.y) / f->zoom));
	}
	update_world(f);
	return (0);
}
