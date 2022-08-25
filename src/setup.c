/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:16:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 02:18:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "fractol.h"
#include "ft_printf.h"
#include "ft_math.h"

void	init_color_range(t_fract *f)
{
	(*(f->ran + 0)) =
		(t_ran){{0xE0E0E0, 0x818181, 0x606060, 0x3B3B3B, 0x262626}, 5};
	(*(f->ran + 1)) =
		(t_ran){{0x9E95ED, 0xC161DC, 0x4ED3B0, 0xF2B061, 0xF76E61}, 5};
	(*(f->ran + 2)) =
		(t_ran){{0xD90D7D, 0xD90BCB, 0x670FBF, 0x36D9BB, 0xF2D43D}, 5};
	(*(f->ran + 3)) =
		(t_ran){{0xc2ffc2, 0x88b388, 0xf0fff0, 0xe1ffe1, 0xffffff}, 5};
	(*(f->ran + 4)) =
		(t_ran){{0xe74645, 0xfb7756, 0xfacd60, 0xfdfa66, 0x1ac0c6}, 5};
	(*(f->ran + 5)) =
		(t_ran){{0xF2778D, 0xF24B88, 0xD9048E, 0x660373, 0xF28A80}, 5};
}

void	init_fract(t_fract *f)
{
	f->render_factor = 1;
	f->it = 50;
	f->prev_zoom = MIN_ZOOM;
	f->zoom = MIN_ZOOM;
	f->szoom = 4;
	f->center = (t_vec2){{0}, {0}};
	f->prev_center = (t_vec2){{0}, {0}};
	f->julia_init = (t_vec2){{0}, {0}};
	f->moving_julia = 0;
	f->exp = 2;
	f->type = KO;
	*(f->func) = znc;
	*(f->func + 1) = bship;
	*(f->func + 2) = ncorn;
	f->menu_toggle = 0;
	f->ran_sel = 1;
	f->func_sel = 0;
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
	menu->ypos = 0;
	menu->img_w = 220;
	menu->img_h = 410;
	menu->img = mlx_new_image(mlx->mlx, menu->img_w, menu->img_h);
	menu->buffer = mlx_get_data_addr(menu->img,
			&(menu->bpp), &(menu->line_size), &(menu->endi));
	fract->render_w = X2K;
	fract->render_h = Y2K;
	return (0);
}

void	print_info(t_fract fract)
{
	(void)fract;
	ft_printf("WELCOME TO THE WOLD OF:\n");
	ft_printf("███████╗██████╗░░█████╗░░█████╗░╗░█████╗░░░░ █████  ██╗░░░░░\n");
	ft_printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝ ░░██╔══██╗██║░░░░░\n");
	ft_printf("█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░░░░██║░░██║██║░░░░░\n");
	ft_printf("██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░██░░██║░░██║██║░░░░░\n");
	ft_printf("██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░╚█████╔╝███████╗\n");
	ft_printf("╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░░╚════╝░╚══════╝\n");
	ft_printf("------------------------------------------------------------\n");
}
