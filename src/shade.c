/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:35:56 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/30 04:53:25 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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

int	iterate(double complex c, int i)
{
	double complex	z;

	z = 0;
	while (i-- && (creal(z) < 2 || cimag(z) < 2))
		z = z * z + c;
	if (creal(z) > 2 || cimag(z) > 2)
		return (0);
	return (1);
}

int	shade(int x, int y, int w, int h)
{
	int		col;
	double	xn;
	double	yn;
	double	aspect;
	double complex c;

	aspect = (double)w / (double)h;
	col = 0x00FFFFFF;
	xn = aspect * ((double)(2 * x) / (double)w - 1);
	yn = ((double)(2 * y) / (double)h - 1);
//	printf("x: %d xn: %f\n", x, xn);
//	printf("y: %d yn: %f\n", y, yn);
//	printf("C: %f\n", sqrt(exp2(xn) + exp2(yn)));
	c = CMPLX(xn, yn);
	if (iterate(c, 100))
		col = color(255, 0, 0, 0);
	return (col);
}
