/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:16:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/05 13:52:28 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"
#include "ft_math.h"

t_vec2	screen_to_world(t_fract f, int x, int y)
{
	t_vec2	c;

	c.r = ((double)x / (double)f.img->img_w * (f.world[2] - f.world[0])) + f.world[0];
	c.i = ((double)y / (double)f.img->img_h * (f.world[3] - f.world[1])) + f.world[1];
	return (c);
}

void	update_world(t_fract *f)
{
	f->world[0] = f->center[0] - ((((IY1 - IY0) * f->img->aspect) / 2) / f->zoom);
    f->world[1] = -f->center[1] + (IY0 / f->zoom);
    f->world[2] = f->center[0] + ((((IY1 - IY0) * f->img->aspect) / 2) / f->zoom);
    f->world[3] = -f->center[1] + (IY1 / f->zoom);
}

int	setup(t_fract *fract, int width, int height)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = fract->mlx;
	img = fract->img;
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
	fract->center[0] = 0.0;
	fract->center[1] = 0.0;
	fract->zoom = 100;
	fract->szoom = 4;
	fract->it = 100;
	fract->func = znc;
	fract->julia_init.r = 0.355;
	fract->julia_init.i = 0.355;
	fract->render_factor = 1;
	return (0);
}

void	print_info(t_fract fract)
{
	t_mlx	mlx;;
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
	ft_printf("\nUseful INFO:\n\n");
	ft_printf("Window Width: %d\n", mlx.win_w);
	ft_printf("Window Height: %d\n", mlx.win_h);
	ft_printf("Image BPP: %d\n", img.bpp);
	ft_printf("Image Line Size: %d\n", img.line_size);
	ft_printf("TODO: Initial Zoom: %f\n", fract.zoom);
	ft_printf("TODO: Initial Iterations: %f\n", fract.it);
	ft_printf("TODO: Initial exp: %d\n", fract.exp);
	if (img.endi == FT_LITTLE_ENDIAN)
		ft_printf("Little Endian");
	else
		ft_printf("Big Endian");
}
