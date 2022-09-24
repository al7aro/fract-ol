/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:16:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:12:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "fractol.h"
#include "ft_math.h"

void	init_color_range(t_fract *f)
{
	(*(f->ran + 0)) = (t_ran)
	{{0xE0E0E0, 0x818181, 0x606060, 0x3B3B3B, 0x262626}, 5};
	(*(f->ran + 1)) = (t_ran)
	{{0x9E95ED, 0xC161DC, 0x4ED3B0, 0xF2B061, 0xF76E61}, 5};
	(*(f->ran + 2)) = (t_ran)
	{{0xD90D7D, 0xD90BCB, 0x670FBF, 0x36D9BB, 0xF2D43D}, 5};
	(*(f->ran + 3)) = (t_ran)
	{{0xc2ffc2, 0x88b388, 0xf0fff0, 0xe1ffe1, 0xffffff}, 5};
	(*(f->ran + 4)) = (t_ran)
	{{0xe74645, 0xfb7756, 0xfacd60, 0xfdfa66, 0x1ac0c6}, 5};
	(*(f->ran + 5)) = (t_ran)
	{{0xF2778D, 0xF24B88, 0xD9048E, 0x660373, 0xF28A80}, 5};
}

void	init_fract(t_fract *f)
{
	init_color_range(f);
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
	*(f->func + 3) = zninvc;
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
	mlx->res = (t_vec2){{width}, {height}};
	img->res = (t_vec2){{mlx->res.w}, {mlx->res.h}};
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, mlx->res.w, mlx->res.h, "fract-ol");
	if (!mlx->win)
		return (1);
	img->img = mlx_new_image(mlx->mlx, img->res.w, img->res.h);
	img->buffer = mlx_get_data_addr(img->img,
			&(img->bpp), &(img->line_size), &(img->endi));
	img->aspect = (double)width / (double)height;
	menu->pos = (t_vec2){{0}, {0}};
	menu->res = (t_vec2){{220}, {410}};
	menu->img = mlx_new_image(mlx->mlx, menu->res.w, menu->res.h);
	menu->buffer = mlx_get_data_addr(menu->img,
			&(menu->bpp), &(menu->line_size), &(menu->endi));
	return (0);
}

void	print_info(t_fract fract)
{
	(void)fract;
	printf("WELCOME TO THE WOLD OF:\n");
	printf("███████╗██████╗░░█████╗░░█████╗░╗░█████╗░░░░ █████  ██╗░░░░░\n");
	printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝ ░░██╔══██╗██║░░░░░\n");
	printf("█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░░░░██║░░██║██║░░░░░\n");
	printf("██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░██░░██║░░██║██║░░░░░\n");
	printf("██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░╚█████╔╝███████╗\n");
	printf("╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░░╚════╝░╚══════╝\n");
	printf("------------------------------------------------------------\n");
}
