/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/30 16:26:27 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "fractol.h"
#include "utils.h"
#include "hooks.h"
#define FT_WIDTH 1080
#define FT_HEIGHT 720

int	main(void)
{
	t_mlx	mlx;
	t_img	main_buffer;
	void	*info[2];

	*(info) = (void *)&mlx;
	*(info + 1) = (void *)&main_buffer;
	if (setup(info, FT_WIDTH, FT_HEIGHT))
		return (1);
	print_info(mlx, main_buffer);
	mlx_loop_hook(mlx.mlx, update_frame, info);
	mlx_key_hook(mlx.win, key_pressed, NULL);
	mlx_loop(mlx.mlx);
	return (1);
}
