/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:04 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 23:09:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <math.h>

t_vec2	znc(t_vec2 z, t_vec2 c, int exp)
{
	t_vec2	m;

	(void)exp;
	m.r = (pow(z.r, 2) - pow(z.i, 2)) + c.r;
	m.i = (2 * z.r * z.i) + c.i;
	return (m);
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
