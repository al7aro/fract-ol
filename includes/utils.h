/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:18:33 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 15:11:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "mlx.h"
# include "fractol.h"

void	update_world(t_fract *f);
int		setup(t_fract *fract, int width, int height);
void	print_info(t_mlx mlx, t_img img);
int		color(unsigned char r, unsigned char g, unsigned char b,
			unsigned char a);
int		pixel_buffer_put(t_img *img, int x, int y, int color);
int		update_frame(void **param);

#endif
