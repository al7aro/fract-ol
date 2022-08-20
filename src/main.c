/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 23:45:30 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "fractol.h"
#include "utils.h"
#include "shade.h"
#include "hooks.h"
#include "parser.h"
#include "error.h"
#define FT_WIDTH 1080
#define FT_HEIGHT 1080

void	exit_status(t_err status)
{
	if (status == INVALID_ARGUMENT)
		exit(1);
}

int	clean_exit(void *param)
{
	(void)param;
	exit(0);
}

void	init_fract(t_fract *f)
{
	f->render_factor = 1;
	f->it = 50;
	f->prev_zoom = MIN_ZOOM;
	f->zoom = MIN_ZOOM;
	f->szoom = 4;
	f->center.x = 0.0;
	f->center.y = 0.0;
	f->julia_init.r = 0.0;
	f->julia_init.i = 0.0;
	f->exp = 2;
	f->type = KO;
	f->func = bship;
	f->menu_toggle = 0;
	(*(f->ran + 0)) = (t_ran){{0xE0E0E0, 0x818181, 0x606060, 0x3B3B3B, 0x262626}, 5};
	(*(f->ran + 1)) = (t_ran){{0x9E95ED, 0xC161DC, 0x4ED3B0, 0xF2B061, 0xF76E61}, 5};
	(*(f->ran + 2)) = (t_ran){{0xD90D7D, 0xD90BCB, 0x670FBF, 0x36D9BB, 0xF2D43D}, 5};
	(*(f->ran + 3)) = (t_ran){{0xc2ffc2, 0x88b388, 0xf0fff0, 0xe1ffe1, 0xffffff}, 5};
	(*(f->ran + 4)) = (t_ran){{0xe74645, 0xfb7756, 0xfacd60, 0xfdfa66, 0x1ac0c6}, 5};
	f->ran_sel = 1;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	main_buffer;
	t_img	menu;
	t_fract	frac;

	frac.mlx = &mlx;
	frac.img = &main_buffer;
	frac.menu = &menu;
	init_fract(&frac);
	if (parse_args(argc, argv, &frac) != OK)
		exit_status(INVALID_ARGUMENT);
	if (setup(&frac, FT_WIDTH, FT_HEIGHT))
		exit_status(OK);
	update_world(&frac);
	print_info(frac);
	mlx_hook(mlx.win, 17, 0, clean_exit, NULL);
	mlx_hook(mlx.win, 2, 0, key_pressed, &frac);
	mlx_mouse_hook(mlx.win, mouse_pressed, &frac);
	mlx_loop_hook(mlx.mlx, on_loop, &frac);
	mlx_loop(mlx.mlx);
	return (0);
}
