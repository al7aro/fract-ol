/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vid_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:04:34 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 15:58:12 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "utils.h"
#include "ft_printf.h"
#include "libft.h"
#include "render.h"
#include <fcntl.h>
#include <math.h>

void	vid_export(t_fract *f)
{
	int		fd;
	int		x;
	int		y;
	int		completed;

	render_menu(f);
	fd = open("renders/new.ppm", O_CREAT | O_RDWR);
	y = -1;
	write(fd, "P3\n2048 1080\n255\n", 17);
	f->img->aspect = (double)X2K / (double)Y2K;
	update_world(f);
	while (++y < Y2K)
	{
		x = -1;
		while (++x < Y2K)
			write_color(fd, shade(x, y, *f, 1));
		completed = y * 100 / Y2K;
		mlx_string_put(f->mlx->mlx, f->mlx->win,
			((float)(completed / (float)100)) * (f->menu->res.w - 10),
			f->menu->pos.y + f->menu->res.h - 20, 0x00FF0000, ".");
		mlx_do_sync(f->mlx->mlx);
	}
	f->img->aspect = (double)f->mlx->res.w / (double)f->mlx->res.h;
	update_world(f);
	close(fd);
}
