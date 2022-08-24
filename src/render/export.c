/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:04:34 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/24 01:28:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "utils.h"
#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>
#include <math.h>

void	write_color(int fd, int col)
{
	char	*scolor;

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

int	render_export(t_fract *f)
{
	int		fd;
	int		x;
	int		y;
	int		completed;

	render_menu(f);
	fd = open("renders/new.ppm", O_CREAT | O_RDWR);
	y = -1;
	write(fd, "P3\n2048 1080\n255\n", 17);
	f->img->aspect = (double)f->render_w / (double)f->render_h;
	update_world(f);
	while (++y < f->render_h)
	{
		x = -1;
		while (++x < f->render_h)
			write_color(fd, shade(x, y, *f, 1));
		completed = y * 100 / f->render_h;
		mlx_string_put(f->mlx->mlx, f->mlx->win,
			((float)(completed / (float)100)) * (f->menu->img_w - 10),
			f->menu->ypos + f->menu->img_h - 20, 0x00FF0000, ".");
		mlx_do_sync(f->mlx->mlx);
	}
	f->img->aspect = (double)f->mlx->win_w / (double)f->mlx->win_h;
	update_world(f);
	return (close(fd));
}
