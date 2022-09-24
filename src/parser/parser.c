/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:54:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 13:52:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
#include "parser.h"

void	usage(void)
{
	ft_printf("usage:\n\tfract-ol mandelbrot ");
	ft_printf("[-d render] [-f func] [-e exp] \n[-r real] ");
	ft_printf("[-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("\tfract-ol julia -i x y ");
	ft_printf("[-d render] [-f func] [-e exp] \n[-r real] ");
	ft_printf("[-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("Available fract_type:\n");
	ft_printf("\tMANDELBROT\t->\tmandelbrot\t||\tm\n");
	ft_printf("\tJULIA\t\t->\tjulia\t\t||\tj\n\n");
	ft_printf("Options:\n");
	ft_printf("\t\tCOMMAND\t\tDESCRIPTION\t\t\tFRACTAL\n");
	ft_printf("\tfrac_type -d --help\tDisplays render info\t\tm && j\n");
	ft_printf("\tfrac_type -e --help\tDisplays exp info\t\tm && j\n");
	ft_printf("\tfrac_type -i --help\tDisplays imag info\t\tj\n");
	ft_printf("\tfrac_type -z --help\tDisplays zoom info\t\tm && j\n");
	ft_printf("\tfrac_type -n --help\tDisplays iter info\t\tm\n");
	ft_printf("\tfrac_type -c --help\tDisplays center info\t\tm\n");
	ft_printf("\n\t             --help\tDisplays this menu\n");
	exit(0);
}

char	char_is(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	valid(char **argv)
{
	if (**argv != '-')
		usage();
	if (**argv == '-' && !char_is(*(*argv + 1), "deiznec"))
		usage();
}

int	check_compatible(t_opt opt)
{
	if (opt.type == 'j')
	{
		if (!opt.i)
			usage();
	}
	else if (opt.type == 'm')
	{
		if (opt.i)
			usage();
	}
	return (0);
}

/*
 * First arg MUST be fractal type
 * */
int	parse_args(int argc, char **argv, t_fract *f)
{
	t_opt	opt;

	opt.i = 0;
	argv++;
	type_check(argc, argv, f, &opt);
	argv++;
	while (*argv)
	{
		valid(argv);
		opt.cnt = 0;
		render_check(argv, f, &opt);
		exp_check(argv, f, &opt);
		zoom_check(argv, f, &opt);
		iter_check(argv, f, &opt);
		center_check(argv, f, &opt);
		ri_check(argv, f, &opt);
		argv += opt.cnt;
	}
	if (check_compatible(opt))
		usage();
	return (0);
}
