/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:31:36 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/04 15:10:07 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "ft_printf.h"

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
	t_fract	*f;
	t_mlx	*mlx;
	t_img	*img;

	f = ((t_fract *)param);
	mlx = f->mlx;
	img = f->img;
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			pixel_buffer_put(img, x, y, shade(x, y, *f));
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (0);
}
