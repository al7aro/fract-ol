/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:35:56 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:15:52 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "shade.h"
#include "fractol.h"
#include "ft_math.h"
#include <math.h>
#include <stdio.h>

/*
 * Little endian:
 * 0XAARRGGBB
 * color |= ((0x000000FF & a) << 24);
 * */
int	color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	int	color;

	(void)a;
	color = 0;
	color |= ((0x000000FF & r) << 16);
	color |= ((0x000000FF & g) << 8);
	color |= (0x000000FF & b);
	return (color);
}

/*
 * zoom:
 * map [0, 0, w, h] -> [x0, y0, x1, y1]
 * output = output_start + ((output_end - output_start)
	/ (input_end - input_start)) * (input - input_start)
 * xn = x0 + ((x1 - x0) / (w - 0)) * (x - 0)
 * yn = y0 + ((y1 - y0) / (h - 0)) * (y - 0)
 *

	int			range[] = {	0x031a33, 0x031d38, 0x031d38, 0x032344, 0x032950,
							0x042f5b, 0x043566, 0x053b72, 0x05417d, 0x064789 };
	int			range[] = {0x00FFFFFF, 0x00FF0000, 0x0000FF00, 0x000000FF};

 * world[0] = f.center[0] - ((((IY1 - IY0) * aspect) / 2) / f.zoom);
 * world[1] = f.center[1] + (IY0 / f.zoom);
 * world[2] = f.center[0] + ((((IY1 - IY0) * aspect) / 2) / f.zoom);
 * world[3] = f.center[1] + (IY1 / f.zoom)};
 * */
int	shade(int x, int y, t_fract f, char export)
{
	long double	col;
	t_vec2		z;
	t_vec2		c;
	int			w;
	int			h;

	w = X2K;
	h = Y2K;
	if (!export)
	{
		w = f.img->res.w;
		h = f.img->res.h;
	}
	c.r = ((double)x / (double)w
			* (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)h
			* (f.world[3] - f.world[1])) + f.world[1];
	z.r = f.julia_init.r;
	z.i = f.julia_init.i;
	col = 9.0 * diverges(f, &z, &c) / f.it;
	col -= (int)col;
	if (col < 0)
		return (0);
	return (color_range(col, (*(f.ran + (f.ran_sel % RAN_N))).ran,
			(*(f.ran + (f.ran_sel % RAN_N))).size));
}
