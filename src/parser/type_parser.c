/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:21:25 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 12:44:10 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "fractol.h"
#include "parser.h"

void	julia_usage(void)
{
	ft_printf("usage: fract-ol fractal_type");
	ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("Julia like fractal.\n");
	ft_printf("\n\t--help\t\tDisplay more help");
	exit(0);
}

void	mandelbrot_usage(void)
{
	ft_printf("usage: fract-ol fractal_type");
	ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("Mandelbrot like fractal.\n");
	ft_printf("\n\t--help\t\tDisplay more help");
	exit(0);
}

void	type_check(int argc, char **argv, t_fract *f, t_opt *opt)
{
	if (argc == 1)
		usage();
	if (!(**argv))
		usage();
	if (!ft_strncmp(ft_strtolower(*argv), "mandelbrot", 11)
		|| (**argv == 'm' && ft_strlen(*argv) == 1))
	{
		if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
			mandelbrot_usage();
		f->type = MANDELBROT;
		opt->type = 'm';
	}
	else if (!ft_strncmp(ft_strtolower(*argv), "julia", 6)
		|| (**argv == 'j' && ft_strlen(*argv) == 1))
	{
		if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
			julia_usage();
		f->type = JULIA;
		opt->type = 'j';
	}
	else
		usage();
}
