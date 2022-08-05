/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:54:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/05 14:40:20 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
#include "error.h"


void	render_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify render detail.\n");
	ft_printf("Default: 1\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}
void	zoom_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify initial ZOOM\n");
	ft_printf("Default: 100\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	iter_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify initial number of ITERATIONS to use when func is used\n");
	ft_printf("Default: 100\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	center_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify inital CENTER of image to use when func is used\n");
	ft_printf("Default: [0, 0]\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	ri_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Set initial conditions of a Julia like fractal\n");
	ft_printf("\t-r\t\tSet real part\n");
	ft_printf("\t-i\t\tSet imaginary part\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	exp_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify N to use when func is used\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	func_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify the function to use to calculate fractal, limited to:\n");
	ft_printf("\tznc\t\tz^n + c. Default n = 2\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}

void	usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Options:\n");
	ft_printf("\tfractal_type --help\tDisplays available fractals\n");
	ft_printf("\t-d --help\t\tDisplays render_factor info\n");
	ft_printf("\t-f --help\t\tDisplays func info\n");
	ft_printf("\t-e --help\t\tDisplays exp info\n");
	ft_printf("\t-r --help\t\tDisplays real info\n");
	ft_printf("\t-i --help\t\tDisplays imag info\n");
	ft_printf("\t-z --help\t\tDisplays zoom info\n");
	ft_printf("\t-n --help\t\tDisplays iter info\n");
	ft_printf("\t-c --help\t\tDisplays center info\n");
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
	if (!ft_strncmp(ft_strtolower(*argv), "mandelbrot", 11) || (**argv == 'm' && ft_strlen(*argv) == 1))
		f->type = MANDELBROT;
	else if (!ft_strncmp(ft_strtolower(*argv), "julia", 6) || (**argv == 'j' && ft_strlen(*argv) == 1))
		f->type = JULIA;
	else
		return (INVALID_ARGUMENT);
	argv++;
	while (*argv)
	{
		if (**argv == '-' && *(*argv + 1) == 'd' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisdigit(*(++argv)) || *(*argv) == 48)
				return (INVALID_ARGUMENT);
			f->render_factor = ft_atoi(*argv);
		}
		else if (**argv == '-' && *(*argv + 1) == 'f' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisalpha(*(++argv)))
				return (INVALID_ARGUMENT);
			ft_printf("Check -f");
		}
		else if (**argv == '-' && *(*argv + 1) == 'e' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisdigit(*(++argv)) || *(*argv) == 48)
				return (INVALID_ARGUMENT);
			f->exp = ft_atoi(*argv);
		}
		else if (**argv == '-' && *(*argv + 1) == 'z' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisdigit(*(++argv)))
				return (INVALID_ARGUMENT);
			f->zoom = ft_atoi(*argv);
		}
		else if (**argv == '-' && *(*argv + 1) == 'n' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisdigit(*(++argv)))
				return (INVALID_ARGUMENT);
			f->it = ft_atoi(*argv);
		}
		else if (**argv == '-' && *(*argv + 1) == 'c' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisfdigit(*(++argv)) || !ft_strisfdigit(*(++argv)))
				return (INVALID_ARGUMENT);
			//f->center[0] = ft_atof(*argv - 1);
			//f->center[0] = ft_atof(*argv);
		}
		else if (**argv == '-' && *(*argv + 1) == 'r' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisfdigit(*(++argv)))
				return (INVALID_ARGUMENT);
			//f->real = ft_atof(*argv);
		}
		else if (**argv == '-' && *(*argv + 1) == 'i' && ft_strlen(*argv + 1) == 1)
		{
			if (!ft_strisfdigit(*(++argv)))
				return (INVALID_ARGUMENT);
			//f->imag = ft_atof(*argv);
		}
		else
			return (INVALID_ARGUMENT);
		argv++;
	}
	return (OK);
}
