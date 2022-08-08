/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:35:56 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/08 20:47:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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

int	color_normal(long double c)
{
	if (c < 0)
		return (color(0, 0, 0, 0));
	if (c >= 0.0 && c <= 0.25)
	{
		c /= 0.25;
		return color(255, 255 * (1 - c), 255 * (1 - c), 1);
	}
	else if (c > 0.25 && c <= 0.5)
	{
		c = (c - 0.25) / 0.25;
		return color(255 * (1 - c), 255 * c, 0, 1);
	}
	else if (c > 0.5 && c <= 0.75)
	{
		c = (c - 0.5) / 0.25;
		return color(0, 255 * (1 - c), 255 * c, 1);
	}
	else if (c > 0.75 && c <= 1.0)
	{
		c = (c - 0.75) / 0.25;
		return color(255 * c, 255 * c, 255, 1);
	}
	return (color(255, 255, 255, 0));
}

int	diverges(t_fract f, void *init_z, void *init_c)
{
	t_vec2		z;
	t_vec2		c;
	int		i_cnt;
	long double	l;
	t_vec2 		(*func)();
	
	func = f.func;
	i_cnt = 0;
	l = 0;
	if (f.type == MANDELBROT)
	{
		z.r = 0;
		z.i = 0;
		c = *((t_vec2 *)(init_c));
	}
	else if (f.type == JULIA)
	{	
		z = *((t_vec2 *)(init_c));
		c = *((t_vec2 *)(init_z));
	}
	while ((i_cnt++ < f.it) && l < 2)
	{
		z = func(z, c, 0);
		l = ft_length(z.r, z.i);
	}
	if (l > 2)
		return (i_cnt);
	return (-1);
}

/*
 * zoom:
 * map [0, 0, w, h] -> [x0, y0, x1, y1]
 * output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start)
 * xn = x0 + ((x1 - x0) / (w - 0)) * (x - 0)
 * yn = y0 + ((y1 - y0) / (h - 0)) * (y - 0)
 *
 * world[0] = f.center[0] - ((((IY1 - IY0) * aspect) / 2) / f.zoom);
 * world[1] = f.center[1] + (IY0 / f.zoom);
 * world[2] = f.center[0] + ((((IY1 - IY0) * aspect) / 2) / f.zoom);
 * world[3] = f.center[1] + (IY1 / f.zoom)};
 * */
int	shade(int x, int y, t_fract f)
{
	long double	col;
	int		d;	
	t_vec2		z;
	t_vec2		c;
	
	c.r = ((double)x / (double)f.img->img_w * (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)f.img->img_h * (f.world[3] - f.world[1])) + f.world[1];
	z.r = f.julia_init.r;
	z.i = f.julia_init.i;
	d = diverges(f, &z, &c);
	col = d / f.it;
	if (col < 0)
		return 0;
	return (color_normal(col));
}
