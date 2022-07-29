/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/29 20:49:35 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "fractol.h"
#include "keycodes.h"
#define _WIDTH 1920
#define _HEIGHT 1080

int	draw(void *param)
{
	t_mlx	mlx;

	mlx = *(t_mlx *)param;
	return (0);
}

int	setup(void **info, int width, int height)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = *info;
	img = *(info + 1);
	mlx->win_w = width;
	mlx->win_h = height;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "fract-ol");
	if (!mlx->mlx)
		return (1);
	img->buffer = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	img->img = mlx_get_data_addr(img->buffer,
			&(img->bpp), &(img->line_size), &(img->endi));
	return (0);
}

int	key_pressed(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;
	t_img	main_buffer;
	void	*info[2];

	*(info) = (void *)&mlx;
	*(info + 1) = (void *)&main_buffer;
	if(setup(info, _WIDTH, _HEIGHT))
		return (1);
	mlx_loop_hook(mlx.mlx, draw, info);
	mlx_key_hook(mlx.win, key_pressed, NULL);
	mlx_loop(mlx.mlx);
	return (1);
}
