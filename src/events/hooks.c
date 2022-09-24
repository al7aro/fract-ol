/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:15:41 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:15:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "keycodes.h"
#include "hooks.h"
#include "libft.h"
#include "fractol.h"
#include "utils.h"
#include "ft_math.h"
#include "temp.h"
#include "shade.h"

#include <stdio.h>

/*
 * Optimizar con los retornos de cada funcion
 * */
int	hook_key_pressed(int keycode, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	move(keycode, f);
	visual(keycode, f);
	iter(keycode, f);
	menu(keycode, f);
	type(keycode, f);
	update_world(f);
	return (0);
}

int	hook_mouse_pressed(int button, int x, int y, void *param)
{
	t_fract		*f;

	f = (t_fract *)param;
	mouse_scroll(button, x, y, f);
	mouse_type(button, x, y, f);
	return (0);
}

int	hook_mouse_move(int x, int y, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	mouse_move(x, y, f);
	return (0);
}
