/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:13:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/29 20:15:27 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_img
{
	void	*buffer;
	void	*img;
	int		bpp;
	int		line_size;
	int		endi;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;
}				t_mlx;

#endif
