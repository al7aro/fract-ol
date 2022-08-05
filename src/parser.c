/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:54:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/05 02:46:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
#include "error.h"

void	ri_usage()
{
	ft_printf("usage: fract-ol fractal_type [-f func] [-e exp] [-r real] [-i imag]\n");
	ft_printf("Set initial conditions of a Julia like fractal\n");
	ft_printf("\t-r\t\tSet real part\n");
	ft_printf("\t-i\t\tSet imaginary part\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	exp_usage()
{
	ft_printf("usage: fract-ol fractal_type [-f func] [-e exp] [-r real] [-i imag]\n");
	ft_printf("Specify N to use when func is used\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	func_usage()
{
	ft_printf("usage: fract-ol fractal_type [-f func] [-e exp] [-r real] [-i imag]\n");
	ft_printf("Specify the function to use to calculate fractal, limited to:\n");
	ft_printf("\tznc\t\tz^n + c. Default n = 2\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	usage()
{
	ft_printf("usage: fract-ol fractal_type [-f func] [-e exp] [-r real] [-i imag]\n");
	ft_printf("Options:\n");
	ft_printf("\tfractal_type --help\tDisplays available fractals\n");
	ft_printf("\t-f --help\t\tDisplays func info\n");
	ft_printf("\t-e --help\t\tDisplays exp info\n");
	ft_printf("\t-r --help\t\tDisplays real info\n");
	ft_printf("\t-i --help\t\tDisplays imag info\n");
	ft_printf("\t--help\t\t\tDisplays this menu\n");
}

/*
 * First arg MUST be fractal type
 * */
t_err	parse_args(int argc, char **argv, t_fract *f)
{
	f->type = KO;
	argv++;
	if (argc == 1)
		return (INVALID_ARGUMENT);
	if (!ft_strncmp(ft_strtolower(*argv), "mandelbrot", 11))
		f->type = MANDELBROT;
	if (!ft_strncmp(ft_strtolower(*argv), "julia", 6))
		f->type = JULIA;
	if (f->type == KO)
		return (INVALID_ARGUMENT);
	(void)argc;
	(void)argv;
	(void)f;
	return (OK);
}
