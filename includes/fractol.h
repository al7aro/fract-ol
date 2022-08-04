/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:13:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 15:10:40 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_math.h"
# define FT_LITTLE_ENDIAN 0
# define FT_BIG_ENDIAN 1
# define IX0 -2.0
# define IY0 -1.0

# define IY1 1.0
# define IZOOM

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
	double	zoom;
	double	world[4];
}				t_fract;

#endif
