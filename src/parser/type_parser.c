/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:21:25 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/07 19:40:12 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "error.h"
#include "fractol.h"

void	julia_usage()
{
		ft_printf("usage: fract-ol fractal_type");
		ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
		ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
		ft_printf("Julia like fractal.\n");
		ft_printf("\n\t--help\t\tDisplay more help");
}

void	mandelbrot_usage()
{
		ft_printf("usage: fract-ol fractal_type");
		ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
		ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
		ft_printf("Mandelbrot like fractal.\n");
		ft_printf("\n\t--help\t\tDisplay more help");
}

t_err	type_usage(t_err err)
{
	if (err == JULIA_USAGE)
		julia_usage();
	else if(err == MANDELBROT_USAGE)
		mandelbrot_usage();
	else
	{
		ft_printf("usage: fract-ol fractal_type");
		ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
		ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
		ft_printf("Specify the fractal family to be used, limited to:\n");
		ft_printf("\tMANDELBROT\t->\tmandelbrot || m\n");
		ft_printf("\tJULIA\t\t->\tjulia || j\n");
		ft_printf("\n\tfractal_type --help\t\tDisplay more help");
		ft_printf("\n\t--help\t\t\t\tDisplay more help");
	}
	return (INVALID_ARGUMENT);
}

t_err	type_check(int argc, char **argv, t_fract *f)
{
	if (argc == 1)
		return (INVALID_ARGUMENT);
	if (!ft_strncmp(ft_strtolower(*argv), "mandelbrot", 11)
		|| (**argv == 'm' && ft_strlen(*argv) == 1))
	{
		if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
			return (MANDELBROT_USAGE);
		f->type = MANDELBROT;
	}
	else if (!ft_strncmp(ft_strtolower(*argv), "julia", 6)
		|| (**argv == 'j' && ft_strlen(*argv) == 1))
	{
		if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
			return (JULIA_USAGE);
		f->type = JULIA;
	}
	else if (!ft_strncmp(ft_strtolower(*argv), "fractals", 6)
		|| (**argv == 'j' && ft_strlen(*argv) == 1))
	{
		if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
			return (TYPE_USAGE);
	}
	else
		return (INVALID_ARGUMENT);
	return (OK);
}
