/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:31:36 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/30 03:58:06 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"

/*
 * 0 R
 * 1 G
 * 2 B
 * 3 A
 * */
int	pixel_buffer_put(t_img *img, int x, int y, int color)
{
	int	first_char;

	first_char = x * (img->bpp / 8) + y * img->line_size;
	*(img->buffer + first_char + 0) = (char)((color & 0x000000FF) >> 0);
	*(img->buffer + first_char + 1) = (char)((color & 0x0000FF00) >> 8);
	*(img->buffer + first_char + 2) = (char)((color & 0x00FF0000) >> 16);
	*(img->buffer + first_char + 3) = (char)((color & 0xFF000000) >> 24);
	return (0);
}

int	update_frame(void **param)
{
	int		x;
	int		y;
	t_mlx	*mlx;
	t_img	*img;

	mlx = (t_mlx *)*param;
	img = (t_img *)*(param + 1);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			pixel_buffer_put(img, x, y, shade(x, y, img->img_w, img->img_h));
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
