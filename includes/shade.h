/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:36:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 03:09:51 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADE_H
# define SHADE_H

typedef struct s_range
{
	int		*colors;
	char	n;
}				t_range;

int	shade(int x, int y, t_fract f, char exp);
int	color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

int	wrgbw_range(long double c);
int	swamp_range(long double c);
int	color_range(long double c, int *colors, int n);
#endif
