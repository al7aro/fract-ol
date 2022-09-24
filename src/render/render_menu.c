/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 01:50:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:12:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "shade.h"
#include "utils.h"
#include "libft.h"
#include <fcntl.h>
#include <math.h>

char	*str_to_win(t_fract *f, char *str, int x, int y)
{
	mlx_string_put(f->mlx->mlx, f->mlx->win, f->menu->pos.x + x,
		f->menu->pos.y + y, 0x00FFFFFF, str);
	return (str);
}

void	put_status_str(t_fract *f)
{
	char	*tmp;

	str_to_win(f, "--------STATUS--------", 0, 20);
	tmp = ft_ftoa(f->mlx->res.w, 9);
	free(str_to_win(f, ft_strjoin("WIDTH: ", tmp), 10, 40));
	free(tmp);
	tmp = ft_ftoa(f->mlx->res.h, 9);
	free(str_to_win(f, ft_strjoin("HEIGHT: ", tmp), 10, 60));
	free(tmp);
	tmp = ft_ftoa(f->center.x, 9);
	free(str_to_win(f, ft_strjoin("Re: ", tmp), 10, 80));
	free(tmp);
	tmp = ft_ftoa(f->center.y, 9);
	free(str_to_win(f, ft_strjoin("Im: ", tmp), 10, 100));
	free(tmp);
	tmp = ft_ultoa(f->zoom);
	free(str_to_win(f, ft_strjoin("Zoom: ", tmp), 10, 120));
	free(tmp);
	tmp = ft_ultoa(f->it);
	free(str_to_win(f, ft_strjoin("It: ", tmp), 10, 140));
	free(tmp);
	tmp = ft_itoa(f->render_factor);
	free(str_to_win(f, ft_strjoin("Scale: 1/", tmp), 10, 160));
	free(tmp);
}

void	put_op_str(t_fract *f)
{
	char	*tmp;

	str_to_win(f, "OP: ", 10, 180);
	if (f->type == MANDELBROT)
		str_to_win(f, "Mandelbrot", 40, 180);
	else if (f->type == JULIA)
	{
		str_to_win(f, "Julia", 40, 180);
		tmp = ft_ftoa(f->julia_init.x, 9);
		free(str_to_win(f, ft_strjoin("Re: ", tmp), 10, 200));
		free(tmp);
		tmp = ft_ftoa(f->julia_init.y, 9);
		free(str_to_win(f, ft_strjoin("Im: ", tmp), 10, 220));
		free(tmp);
	}
}

void	put_function_str(t_fract *f)
{
	str_to_win(f, "Function: ", 10, 240);
	str_to_win(f, "Exp: ", 10, 260);
	free(str_to_win(f, ft_itoa(f->exp), 45, 260));
	if (*(f->func + f->func_sel % FUNC_N) == znc)
	{
		str_to_win(f, "MANDELBROT", 80, 240);
		str_to_win(f, "z = z^exp + c", 10, 280);
	}
	else if (*(f->func + f->func_sel % FUNC_N) == ncorn)
	{
		str_to_win(f, "NCORN", 80, 240);
		str_to_win(f, "z.Im = -z.Im", 10, 280);
		str_to_win(f, "z = z^exp + c", 10, 300);
	}
	else if (*(f->func + f->func_sel % FUNC_N) == bship)
	{
		str_to_win(f, "B. SHIP", 80, 240);
		str_to_win(f, "z = abs(z)^exp + c", 10, 280);
	}
	str_to_win(f, "COLOR PALETTE", 10, 320);
}

void	render_menu(t_fract *f)
{
	int	x;
	int	y;
	int	col;
	int	cnt;

	y = -1;
	while (++y < f->menu->res.h)
	{
		x = -1;
		while (++x < f->menu->res.w)
		{
			cnt = -1;
			col = 0;
			while (++cnt < (*(f->ran + f->ran_sel % RAN_N)).size)
				if (abs(x - (30 + 40 * cnt)) < 20
					&& fabsl(y - (f->menu->res.h * 0.85)) < 20)
					col = ((*(f->ran + f->ran_sel % RAN_N)).ran[cnt]);
			pixel_buffer_put(f->menu, x, y, col);
		}
	}
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->menu->img,
		f->menu->pos.x, f->menu->pos.y);
	put_status_str(f);
	put_op_str(f);
	put_function_str(f);
}
