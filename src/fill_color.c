/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:31:36 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 17:13:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "utils.h"
#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>

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
	int		y_limit;
	t_img	*img;

	img = f->img;
	y = -1;
	y_limit = img->img_h;
	if (f->menu_toggle)
		y_limit = f->menu->ypos;
	while (++y < y_limit)
	{
		x = -1;
		while (++x < img->img_w)
		{
			if (!(x % f->render_factor))
				col = shade(x, y, *f);
			pixel_buffer_put(img, x, y, col);
		}
	}
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->img->img, 0, 0);
	return (0);
}

int	render_menu(t_fract *f)
{
	int		col;
	int		x;
	int		y;
	t_img	*menu;

	menu = f->menu;
	y = menu->ypos;
	while (++y < menu->img_h)
	{
		x = -1;
		while (++x < menu->img_w)
		{
			if (!(x % f->render_factor))
				col = 0x00FFFFFF;
			pixel_buffer_put(menu, x, y, col);
		}
	}
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->menu->img, f->menu->xpos, f->menu->ypos);
	mlx_string_put(f->mlx->mlx, f->mlx->win, f->menu->xpos + 10, f->menu->ypos + 20, 0x00FFFFFF, "FRACT-OL");
	return (0);
}

int	render_export(t_fract *f)
{
	int		fd;
	int		col;
	int		x;
	int		y;
	int		completed;
	char	*scolor;
	t_img	*img;

	completed = 0;
	render_menu(f);
	fd = open("renders/new.ppm", O_CREAT | O_RDWR);
	img = f->img;
	y = -1;
	write(fd, "P3\n", 3);
	write(fd, "2048 1080\n", 10);
	write(fd, "255\n", 4);
	while (++y < Y2K)
	{
		x = -1;
		while (++x < X2K)
		{
			col = shade(x, y, *f);
			scolor = ft_itoa((col & 0x00FF0000) >> 16);
			write(fd, scolor, ft_strlen(scolor));
			free(scolor);
			write(fd, " ", 1);
			scolor = ft_itoa((col & 0x0000FF00) >> 8);
			write(fd, scolor, ft_strlen(scolor));
			free(scolor);
			write(fd, " ", 1);
			scolor = ft_itoa((col & 0x000000FF));
			write(fd, scolor, ft_strlen(scolor));
			free(scolor);
			write(fd, "\n", 1);
		}
		mlx_string_put(f->mlx->mlx, f->mlx->win, 10, f->mlx->win_h - 40, 0x00000000, "NOW RENDERING");
		mlx_string_put(f->mlx->mlx, f->mlx->win, 10, f->mlx->win_h - 40, 0x00FFFFFF, "NOW RENDERING");
		mlx_string_put(f->mlx->mlx, f->mlx->win, f->mlx->win_w - 40, f->mlx->win_h - 40, 0x00000000, ft_itoa(completed));
		completed = y * 100 / Y2K;
		mlx_string_put(f->mlx->mlx, f->mlx->win, f->mlx->win_w - 40, f->mlx->win_h - 40, 0x0000FF00, ft_itoa(completed));
		mlx_string_put(f->mlx->mlx, f->mlx->win, (float)(completed/(float)100)
				* f->mlx->win_w, f->mlx->win_h - 20, 0x00FFFFFF, "-");
		mlx_do_sync(f->mlx->mlx);
	}
	close(fd);
	return (0);
}

int	on_loop(void **param)
{
	t_fract	*f;

	f = ((t_fract *)param);
	if (f->img)
		render_fractal(f);
	if (f->menu && f->menu_toggle)
		render_menu(f);
	return (0);
}
