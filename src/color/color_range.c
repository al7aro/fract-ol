/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 022/08/19 17:34:45 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:15:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <math.h>
#include <stdlib.h>

int	color_range(long double c, int *colors, int n)
{
	long double	rdiff;
	long double	gdiff;
	long double	bdiff;
	int			cnt;
	long double	step;

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
