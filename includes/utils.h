/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:18:33 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 02:13:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "mlx.h"
# include "fractol.h"
# include "ft_math.h"

t_vec2	screen_to_world(t_fract f, int x, int y);
void	update_world(t_fract *f);
int		setup(t_fract *fract, int width, int height);
void	print_info(t_fract fract);
int		color(unsigned char r, unsigned char g, unsigned char b,
			unsigned char a);
int		pixel_buffer_put(t_img *img, int x, int y, int color);
int		on_loop(void **param);
int		clean_exit(void *param);
void	init_fract(t_fract *f);

#endif
