/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:22:02 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/31 19:44:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "fractol.h"
#include <math.h>

t_vec2	znc(t_vec2 z, t_vec2 c, int exp)
{
	t_vec2	z_pow;

	z_pow = ft_cpow(z, exp);
	z_pow.r += c.r;
	z_pow.i += c.i;
	return (z_pow);
}

t_vec2	zninvc(t_vec2 z, t_vec2 c, int exp)
{
	c = ft_cinv(c);
	return (znc(z, c, exp));
}

t_vec2	ncorn(t_vec2 z, t_vec2 c, int exp)
{
	(void)exp;
	z.i = -z.i;
	return (znc(z, c, exp));
}

t_vec2	bship(t_vec2 z, t_vec2 c, int exp)
{
	(void)exp;
	z.r = fabsl(z.r);
	z.i = fabsl(z.i);
	return (znc(z, c, exp));
}
