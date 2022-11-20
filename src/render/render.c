/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:31:36 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/20 23:43:46 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "utils.h"
#include "libft.h"
#include <fcntl.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include "render.h"

/*
 * 0 R
 * 1 G
 * 2 B
 * 3 A
 * */
int	pixel_buffer_put(t_img *img, int x, int y, int c)
{
	int	first_char;

	first_char = x * (img->bpp / 8) + y * img->line_size;
	*(img->buffer + first_char + 0) = (char)((c & 0x000000FF) >> 0);
	*(img->buffer + first_char + 1) = (char)((c & 0x0000FF00) >> 8);
	*(img->buffer + first_char + 2) = (char)((c & 0x00FF0000) >> 16);
	*(img->buffer + first_char + 3) = (char)((c & 0xFF000000) >> 24);
	return (0);
}

	pthread_mutex_t m;
void	*render_fractal(void *param)
{
	t_fract *f = ((t_fract *)*((void **)param)); 
	int		col;
	int		x;
	int		y;
	int		y_limit;
	t_img	*img;
	int		n = *((int *)*((void **)param + 1));

	(void)n;
	fflush(stdout);
	img = f->img;
	y = 0;
	y_limit = img->res.h;
	while (y < y_limit)
	{
		x = 0;
		while (x < img->res.w)
		{
			if (!(x % f->render_factor))
				col = shade(x, y, *f, 0);
			pixel_buffer_put(img, x, y, col);
			x += 1;
		}
		y += 1;
	}
	pthread_exit(NULL);
}

void	*numdup(int n)
{
	int	*num;

	num = (int *)malloc(sizeof(int));
	*num = n;
	return ((void *)num);
}

int	on_loop(void **param)
{
	int		cnt = -1;
	int		threadsno = 100;
	t_fract	*f;
	void	**p;

	f = ((t_fract *)param);
	if (f->img)
	{
		while (++cnt <= threadsno)
		{
			p = (void **)malloc(sizeof(void *) * 3);
			*p = (void *)f;
			*(p + 1) = numdup(cnt);
			*(p + 2) = malloc(sizeof(pthread_t *));
			pthread_create((pthread_t *)*(p + 2), NULL, render_fractal, p);
			pthread_join(*(p + 2), NULL);
		}
	}
	if (f->menu && f->menu_toggle)
		render_menu(f);
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->img->img, 0, 0);
	return (0);
}
