/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:56:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/21 17:39:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycodes.h"
#include "fractol.h"
#include <stdlib.h>

int	move(int keycode, t_fract *f)
{
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
	return (0);
}
