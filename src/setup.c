/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:16:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 22:27:56 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"
#include "ft_math.h"

t_vec2	screen_to_world(t_fract f, int x, int y)
{
	t_vec2	c;

	c.r = ((double)x / (double)f.img->img_w
			* (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)f.img->img_h
			* (f.world[3] - f.world[1])) + f.world[1];
	return (c);
}

void	update_world(t_fract *f)
{
	f->world[0] = f->center.x
		- ((((IY1 - IY0) * f->img->aspect) / 2) / f->zoom);
	f->world[1] = -f->center.y + (IY0 / f->zoom);
	f->world[2] = f->center.x
		+ ((((IY1 - IY0) * f->img->aspect) / 2) / f->zoom);
	f->world[3] = -f->center.y + (IY1 / f->zoom);
}

int	setup(t_fract *fract, int width, int height)
{
	t_mlx	*mlx;
	t_img	*img;
	t_img	*menu;

	mlx = fract->mlx;
	img = fract->img;
	menu = fract->menu;
	mlx->win_w = width;
	mlx->win_h = height;
	img->img_w = mlx->win_w;
	img->img_h = mlx->win_h;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "fract-ol");
	if (!mlx->win)
		return (1);
	img->img = mlx_new_image(mlx->mlx, img->img_w, img->img_h);
	img->buffer = mlx_get_data_addr(img->img,
			&(img->bpp), &(img->line_size), &(img->endi));
	img->aspect = (double)width / (double)height;
	menu->xpos = 0;
	menu->ypos = 0.7 * height;
	menu->img_w = width;
	menu->img_h = img->img_h - menu->ypos;
	menu->img = mlx_new_image(mlx->mlx, menu->img_w, menu->img_h);
	menu->buffer = mlx_get_data_addr(menu->img,
			&(menu->bpp), &(menu->line_size), &(menu->endi));
	fract->render_w = X2K;
	fract->render_h = Y2K;
	return (0);
}

void	print_info(t_fract fract)
{
	t_mlx	mlx;
	t_img	img;

	mlx = *fract.mlx;
	img = *fract.img;
	ft_printf("WELCOME TO THE WOLD OF:\n");
	ft_printf("███████╗██████╗░░█████╗░░█████╗░╗░█████╗░░░░ █████  ██╗░░░░░\n");
	ft_printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝ ░░██╔══██╗██║░░░░░\n");
	ft_printf("█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░░░░██║░░██║██║░░░░░\n");
	ft_printf("██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░██░░██║░░██║██║░░░░░\n");
	ft_printf("██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░╚█████╔╝███████╗\n");
	ft_printf("╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░░╚════╝░╚══════╝\n");
	ft_printf("------------------------------------------------------------\n");
	if (fract.type == JULIA)
		ft_printf("Rendering a JULIA like fractal!\n");
	else if (fract.type == MANDELBROT)
		ft_printf("Rendering a MANDELBROT like fractal!\n");
	ft_printf("Window Width: %d\n", mlx.win_w);
	ft_printf("Window Height: %d\n", mlx.win_h);
}
