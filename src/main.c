/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/05 00:08:35 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "fractol.h"
#include "utils.h"
#include "hooks.h"
#include "parser.h"
#define FT_WIDTH 500
#define FT_HEIGHT 500

void	exit_status(int status)
{
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
	t_fract	fract;

	fract.mlx = &mlx;
	fract.img = &main_buffer;
	if (parse_args(argc, argv, &fract))
		exit_status(0);
	if (setup(&fract, FT_WIDTH, FT_HEIGHT))
		exit_status(0);
	print_info(mlx, main_buffer);
	mlx_hook(mlx.win, 17, 0, clean_exit, NULL);
	mlx_hook(mlx.win, 2, 0, key_pressed, &fract);
	mlx_mouse_hook(mlx.win, mouse_pressed, &fract);
	mlx_loop_hook(mlx.mlx, push_frame_to_img, &fract);
	mlx_loop(mlx.mlx);
	return (0);
}
