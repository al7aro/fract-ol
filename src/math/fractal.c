/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:04 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/15 12:42:44 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "fractol.h"
#include <math.h>

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
	while ((i_cnt++ < f.it) && l < DIVERGENCE)
	{
		z = (*(f.func + f.func_sel % FUNC_N))(z, c, f.exp);
		l = ft_length(z.r, z.i);
	}
	if (l > DIVERGENCE)
		return (i_cnt);
	return (-1);
}
