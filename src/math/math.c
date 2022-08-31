/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:14:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/31 19:44:09 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <math.h>
#include <stdio.h>

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

t_vec2	ft_cinv(t_vec2 c)
{
	t_vec2		num;
	double long	aux;

	aux = (c.r * c.r - c.i * c.i);
	num = (t_vec2){{c.r / aux}, {-c.i / aux}};
	return (num);
}
