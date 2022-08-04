/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:13:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 23:54:34 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define FT_LITTLE_ENDIAN 0
# define FT_BIG_ENDIAN 1
# define IX0 -1200.0
# define IY0 -600.0

# define IY1 600.0
# define MIN_ZOOM 100.0
# define MANDELBROT 0
# define JULIA 1

#include "ft_math.h"

typedef struct s_img
{
	char	*buffer;
	void	*img;
	int		bpp;
	int		line_size;
	int		endi;
	int		img_w;
	int		img_h;
	double	aspect;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
}				t_mlx;

typedef struct s_fract
{
	t_mlx	*mlx;
	t_img	*img;
	double	center[2];
	double	world[4];
	double	zoom;
	double	szoom;
	int		type;
	void	*func;
	double	it;
}				t_fract;

t_vec2	znc(t_vec2 z, t_vec2 c, int exp);

#endif
