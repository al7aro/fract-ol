/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:24:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/31 17:54:49 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

typedef struct s_vec2
{
	union
	{
		long double	r;
		long double	x;
		long double	w;
	};
	union
	{
		long double	i;
		long double	y;
		long double	h;
	};
}				t_vec2;

typedef struct s_vec4
{
	union
	{
		long double	x;
		long double	x0;
		long double	r;
	};
	union
	{
		long double	y;
		long double	y0;
		long double	g;
	};
	union
	{
		long double	z;
		long double	x1;
		long double	b;
	};
	union
	{
		long double	w;
		long double	y1;
		long double	a;
	};
}				t_vec4;

long double	ft_length(long double x, long double y);
t_vec2		ft_cpow(t_vec2 c, int exp);
t_vec2		ft_cinv(t_vec2 c);

#endif
