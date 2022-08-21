/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:01:34 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/21 18:07:01 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keycodes.h"

int	menu(int keycode, t_fract *f)
{
	if (keycode == M)
		f->menu_toggle = !f->menu_toggle;
	else if (keycode == H)
		f->menu_toggle = !f->menu_toggle;
	return (0);
}
