/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:13:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/30 04:59:58 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define FT_LITTLE_ENDIAN 0
# define FT_BIG_ENDIAN 1

typedef struct s_img
{
	char	*buffer;
	void	*img;
	int		bpp;
	int		line_size;
	int		endi;
	int		img_w;
	int		img_h;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
}				t_mlx;

#endif
