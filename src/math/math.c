/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:14:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:15:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <math.h>

long double	ft_length(long double x, long double y)
{
	long double	l;

	l = sqrt(powl(x, 2) + powl(y, 2));
	return (l);
}

/*
 * Angle:
 * angle = acos(c.r / length) == asin(c.i / length);
 * */
t_vec2	ft_cpow(t_vec2 c, int exp)
{
	t_vec2		num;
	long double	length;
	long double	angle;

	if (c.r == 0 && c.i == 0)
		return (c);
	length = ft_length(c.r, c.i);
	angle = acos(c.r / length);
	if (c.i < 0)
		angle = 2 * M_PI - angle;
	length = powl(length, exp);
	angle = angle * exp;
	num.r = length * cos(angle);
	num.i = length * sin(angle);
	return (num);
}

t_vec2	ft_cmul(t_vec2 c1, t_vec2 c2)
{
	t_vec2	num;

	num.r = (c1.r * c2.r - c1.i * c2.i);
	num.i = (c1.r * c2.i + c1.i * c2.r);
	return (num);
}

t_vec2	ft_cinv(t_vec2 c)
{
	t_vec2	num;
	t_vec2	aux;

	aux = ft_cmul(c, (t_vec2){{c.r}, {-c.i}});
	num = (t_vec2){{c.r / aux.r}, {-c.i / aux.r}};
	return (num);
}
