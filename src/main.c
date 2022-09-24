/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:11:48 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "math.h"
#include "libft.h"
#include "fractol.h"
#include "utils.h"
#include "shade.h"
#include "hooks.h"
#include "parser.h"
#define FT_WIDTH 700
#define FT_HEIGHT 700

int	clean_exit(void *param)
{
	t_fract	*f;

	printf("Program closed suscesfully!\n");
	f = (t_fract *)param;
	mlx_destroy_window(f->mlx->mlx, f->mlx->win);
	free(f->mlx->mlx);
	exit(0);
}

#ifdef DEBUG

void	l(void)
{
	system("leaks fract-ol");
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	main_buffer;
	t_img	menu;
	t_fract	frac;

	atexit(l);
	frac.mlx = &mlx;
	frac.img = &main_buffer;
	frac.menu = &menu;
	init_fract(&frac);
	if (parse_args(argc, argv, &frac))
		clean_exit(&frac);
	if (setup(&frac, FT_WIDTH, FT_HEIGHT))
		clean_exit(&frac);
	update_world(&frac);
	print_info(frac);
	mlx_hook(mlx.win, 17, 0, clean_exit, &frac);
	mlx_hook(mlx.win, 2, 0, hook_key_pressed, &frac);
	mlx_hook(mlx.win, 6, 0, hook_mouse_move, &frac);
	mlx_mouse_hook(mlx.win, hook_mouse_pressed, &frac);
	mlx_loop_hook(mlx.mlx, on_loop, &frac);
	mlx_loop(mlx.mlx);
	return (0);
}

#else

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
	if (parse_args(argc, argv, &frac))
		clean_exit(&frac);
	if (setup(&frac, FT_WIDTH, FT_HEIGHT))
		clean_exit(&frac);
	update_world(&frac);
	print_info(frac);
	mlx_hook(mlx.win, 17, 0, clean_exit, &frac);
	mlx_hook(mlx.win, 2, 0, hook_key_pressed, &frac);
	mlx_hook(mlx.win, 6, 0, hook_mouse_move, &frac);
	mlx_mouse_hook(mlx.win, hook_mouse_pressed, &frac);
	mlx_loop_hook(mlx.mlx, on_loop, &frac);
	mlx_loop(mlx.mlx);
	return (0);
}

#endif
