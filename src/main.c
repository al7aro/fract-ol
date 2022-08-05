/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/05 04:16:47 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "fractol.h"
#include "utils.h"
#include "hooks.h"
#include "parser.h"
#include "error.h"
#define FT_WIDTH 1920
#define FT_HEIGHT 1080

void	exit_status(t_err status)
{
	if (status == INVALID_ARGUMENT)
		usage();
	exit(status);
}

int	clean_exit(void *param)
{
	(void)param;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	main_buffer;
	t_fract	frac;

	frac.mlx = &mlx;
	frac.img = &main_buffer;
	if (setup(&frac, FT_WIDTH, FT_HEIGHT))
		exit_status(OK);
	if (parse_args(argc, argv, &frac) != OK)
		exit_status(INVALID_ARGUMENT);
	update_world(&frac);
	print_info(frac);
	mlx_hook(mlx.win, 17, 0, clean_exit, NULL);
	mlx_hook(mlx.win, 2, 0, key_pressed, &frac);
	mlx_mouse_hook(mlx.win, mouse_pressed, &frac);
	mlx_loop_hook(mlx.mlx, push_frame_to_img, &frac);
	mlx_loop(mlx.mlx);
	return (0);
}
