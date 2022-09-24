/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 02:14:25 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:16:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "fractol.h"
#include "ft_math.h"

t_vec2	screen_to_world(t_fract f, int x, int y)
{
	t_vec2	c;

	c.r = ((double)x / (double)f.img->res.w
			* (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)f.img->res.h
			* (f.world[3] - f.world[1])) + f.world[1];
	return (c);
}

void	update_world(t_fract *f)
{
	f->world[0] = f->center.x
		- ((((IY1 - IY0) * f->img->aspect) / 2) / f->zoom);
	f->world[1] = -f->center.y + (IY0 / f->zoom);
	f->world[2] = f->center.x
		+ ((((IY1 - IY0) * f->img->aspect) / 2) / f->zoom);
	f->world[3] = -f->center.y + (IY1 / f->zoom);
}
