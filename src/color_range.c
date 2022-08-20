/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 022/08/19 17:34:45 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 13:53:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int	wrgbw_range(long double c)
{
	if (c < 0)
		return (color(0, 0, 0, 0));
	if (c >= 0.0 && c <= 0.25)
	{
		c /= 0.25;
		return (color(255, 255 * (1 - c), 255 * (1 - c), 1));
	}
	else if (c > 0.25 && c <= 0.5)
	{
		c = (c - 0.25) / 0.25;
		return (color(255 * (1 - c), 255 * c, 0, 1));
	}
	else if (c > 0.5 && c <= 0.64)
	{
		c = (c - 0.5) / 0.25;
		return (color(0, 255 * (1 - c), 255 * c, 1));
	}
	else if (c > 0.64 && c <= 1.0)
	{
		c = (c - 0.64) / 0.25;
		return (color(255 * c, 255 * c, 255, 1));
	}
	return (color(255, 255, 255, 0));
}

int	color_range(long double c, int *colors, int n)
{
	int		rdiff;
	int		gdiff;
	int		bdiff;
	int		cnt;
	float	step;

	step = 1.0 / --n;
	cnt = -1;
	while (++cnt <= n)
	{
		rdiff = (((*(colors + cnt + 1)) & 0x00FF0000) >> 16)
			- ((*(colors + cnt) & 0x00FF0000) >> 16);
		gdiff = (((*(colors + cnt + 1)) & 0x0000FF00) >> 8)
			- ((*(colors + cnt) & 0x0000FF00) >> 8);
		bdiff = (((*(colors + cnt + 1)) & 0x000000FF))
			- ((*(colors + cnt) & 0x000000FF));
		if (c >= (cnt * step) && c <= (cnt * step + step))
		{
			c = (c - step * cnt) / step;
			return (color((((*(colors + cnt) & 0x00FF0000) >> 16)) + c * rdiff,
					((*(colors + cnt) & 0x0000FF00) >> 8) + c * gdiff,
					((*(colors + cnt) & 0x000000FF)) + c * bdiff, 1));
		}
	}
	return (color(255, 255, 255, 255));
}
