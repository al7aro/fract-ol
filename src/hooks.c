/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:15:41 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 23:34:52 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "keycodes.h"
#include "ft_printf.h"
#include "fractol.h"
#include "utils.h"
#include "ft_math.h"

int	key_pressed(int keycode, void *param)
{
	t_fract *f;

	f = (t_fract *)param;
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP || keycode == W)
		f->center[1] += 40.0 / f->zoom;
	else if (keycode == DOWN || keycode == S)
		f->center[1] -= 40.0 / f->zoom;
	else if (keycode == LEFT || keycode == A)
		f->center[0] -= 40.0 / f->zoom;
	else if (keycode == RIGHT || keycode == D)
		f->center[0] += 40.0 / f->zoom;
	else if (keycode == PLUS)
		f->it += log10(f->zoom);
	else if (keycode == MINUS)
		f->it -= log10(f->zoom);
	update_world(f);
	return (0);
}

int	mouse_pressed(int button, int x, int y, void *param)
{
	t_fract *f;
	t_vec2	w;
	int		prev_zoom;

	f = (t_fract *)param;
	w = screen_to_world(*f, x, y);
	prev_zoom = f->zoom;
	if (button == MSCROLL_DOWN && f->zoom < MAX_ZOOM)
	{
		f->zoom += (f->zoom / f->szoom);
		f->center[0] = (w.r - (prev_zoom * (w.r - f->center[0]) / f->zoom));
		f->center[1] = -(w.i - (prev_zoom * (w.i + f->center[1]) / f->zoom));
		update_world(f);
	}
	if (button == MSCROLL_UP && f->zoom > MIN_ZOOM)
	{
		f->zoom -= (f->zoom / f->szoom);
		f->center[0] = (w.r - (prev_zoom * (w.r - f->center[0]) / f->zoom));
		f->center[1] = -(w.i - (prev_zoom * (w.i + f->center[1]) / f->zoom));
		update_world(f);
	}
	return (0);
}
