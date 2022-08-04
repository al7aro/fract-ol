/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:35:56 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 15:29:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "fractol.h"
#include "ft_printf.h"
#include <math.h>
#include <complex.h>

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

int	diverges(double complex c, int it)
{
	double complex	z;
	int		i_cnt;

	i_cnt = 0;
	z = 0;
	while ((i_cnt++ < it) && creal(z) < 2.0 && cimag(z) < 2.0)
	{
		z = z * z + c;
	}
	if (creal(z) > 2.0 || cimag(z) > 2.0)
		return (i_cnt);
	return (0);
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
	int				col;
	t_vec2	c;
	
	c.r = ((double)x / (double)f.img->img_w * (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)f.img->img_h * (f.world[3] - f.world[1])) + f.world[1];
	if(diverges(CMPLX(c.r, c.i), 100))
		col = 0x000000FF;
	else
		col = 0x00000000;
	return (col);
}
