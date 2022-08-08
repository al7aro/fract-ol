/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:31:36 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/08 16:30:00 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "utils.h"
#include "ft_printf.h"

/*
 * 0 R
 * 1 G
 * 2 B
 * 3 A
 * */
int	pixel_buffer_put(t_img *img, int x, int y, int c)
{
	int	first_char;

	first_char = x * (img->bpp / 8) + y * img->line_size;
	*(img->buffer + first_char + 0) = (char)((c & 0x000000FF) >> 0);
	*(img->buffer + first_char + 1) = (char)((c & 0x0000FF00) >> 8);
	*(img->buffer + first_char + 2) = (char)((c & 0x00FF0000) >> 16);
	*(img->buffer + first_char + 3) = (char)((c & 0xFF000000) >> 24);
	return (0);
}

int	render_fractal(t_fract *f)
{
	int		col;
	int		x;
	int		y;
	t_img	*img;

	img = f->img;
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
		{
			if (!(x % f->render_factor))
				col = shade(x, y, *f);
			pixel_buffer_put(img, x, y, col);
		}
	}
	return (0);
}

int	on_loop(void **param)
{
	t_fract	*f;

	f = ((t_fract *)param);
	render_fractal(f);
	if (f->img)
		mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->img->img, 0, 0);
	if (f->menu)
		mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->menu->img, 0, 0);
	return (0);
}
