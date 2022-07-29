/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:16:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/30 00:00:51 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "ft_printf.h"

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
	if (!mlx->win)
		return (1);
	img->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	img->buffer = mlx_get_data_addr(img->img,
			&(img->bpp), &(img->line_size), &(img->endi));
	img->img_w = mlx->win_w;
	img->img_h = mlx->win_h;
	return (0);
}

void	print_info(t_mlx mlx, t_img img)
{
	ft_printf("WELCOME TO:\n");
	ft_printf("███████╗██████╗░░█████╗░░█████╗░╗░█████╗░░░░ █████  ██╗░░░░░\n");
	ft_printf("██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝ ░░██╔══██╗██║░░░░░\n");
	ft_printf("█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░░░░██║░░██║██║░░░░░\n");
	ft_printf("██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░██░░██║░░██║██║░░░░░\n");
	ft_printf("██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░╚█████╔╝███████╗\n");
	ft_printf("╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░░╚════╝░╚══════╝\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\nUseful INFO:\n\n");
	ft_printf("Window Width: %d\n", mlx.win_w);
	ft_printf("Window Height: %d\n", mlx.win_h);
	ft_printf("Image BPP: %d\n", img.bpp);
	ft_printf("Image Line Size: %d\n", img.line_size);
	if (img.endi == FT_LITTLE_ENDIAN)
		ft_printf("Little Endian");
	else
		ft_printf("Big Endian");
}
