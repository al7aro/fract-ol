/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:15:41 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 15:29:21 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "keycodes.h"
#include "ft_printf.h"
#include "fractol.h"
#include "utils.h"

int	key_pressed(int keycode, void *param)
{
	(void)param;
	ft_printf("%d", keycode);
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	mouse_pressed(int button, int x, int y, void *param)
{
	t_fract *f;

	f = (t_fract *)param;
	(void)button;
	(void)x;
	(void)y;

	if (button == MSCROLL_UP)
	{
		f->zoom += 0.05;
		update_world(f);
	}

	if (button == MSCROLL_DOWN)
	{
		f->zoom -= 0.05;
		if (f->zoom <= 0)
			f->zoom += 0.05;
		update_world(f);
	}
	return (0);
}
