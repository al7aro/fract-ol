/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:35:56 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 19:52:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "shade.h"
#include "fractol.h"
#include "ft_printf.h"
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

int	diverges(t_fract f, void *init_z, void *init_c)
{
	t_vec2		z;
	t_vec2		c;
	int			i_cnt;
	long double	l;

	i_cnt = 0;
	l = 0;
	if (f.type == MANDELBROT)
	{
		z = (t_vec2){{0}, {0}};
		c = *((t_vec2 *)(init_c));
	}
	else if (f.type == JULIA)
	{	
		z = *((t_vec2 *)(init_c));
		c = *((t_vec2 *)(init_z));
	}
	while ((i_cnt++ < f.it) && l < 2)
	{
		z = ((t_vec2 (*)())f.func)(z, c, 0);
		l = ft_length(z.r, z.i);
	}
	if (l > 2)
		return (i_cnt);
	return (-1);
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
	//int			range[] = {0x9E95ED, 0xC161DC, 0x4ED3B0, 0xF2B061, 0xF76E61};
	//int			range[] = {0xE0E0E0, 0x818181, 0x606060, 0x3B3B3B, 0x262626};
	int			range[] = {0xD90D7D, 0xD90BCB, 0x670FBF, 0x36D9BB, 0xF2D43D};

	w = f.render_w;
	h = f.render_h;
	if (!export)
	{
		w = f.img->img_w;
		h = f.img->img_h;
	}
	c.r = ((double)x / (double)w
			* (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)h
			* (f.world[3] - f.world[1])) + f.world[1];
	z.r = f.julia_init.r;
	z.i = f.julia_init.i;
	col = 9 * (diverges(f, &z, &c) / f.it);
	col -= (int)col;
	if (col < 0)
		return (0);
	return (color_range(col, range, 5));
}
