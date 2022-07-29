/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:18:33 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/29 23:40:57 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_C
# define SETUP_C

#include "mlx.h"
#include "fractol.h"

int		setup(void **info, int width, int height);
void	print_info(t_mlx mlx, t_img img);
int		color(unsigned char r, unsigned char g, unsigned char b,
		unsigned char a);
int		pixel_buffer_put(t_img *img, int x, int y, int color);
int		update_frame(void **param);

#endif
