/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:54:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/08 13:58:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
#include "error.h"
#include "parser.h"

void	usage(void)
{
	ft_printf("usage: fract-ol frac_type ");
	ft_printf("[-d render] [-f func] [-e exp] \n[-r real] ");
	ft_printf("[-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Options:\n");
	ft_printf("Each of the following options varies depending");
	ft_printf(" on fractal_type\n");
	ft_printf("\t\tCOMMAND\t\tDESCRIPTION\t\t\tFRACTAL\n");
	ft_printf("\tfractals     --help\tDisplays available frac_type\n");
	ft_printf("\tfrac_type -d --help\tDisplays render info\t\tm && j\n");
	ft_printf("\tfrac_type -f --help\tDisplays func info\t\tm && f\n");
	ft_printf("\tfrac_type -e --help\tDisplays exp info\t\tm && f\n");
	ft_printf("\tfrac_type -r --help\tDisplays real info\t\tj\n");
	ft_printf("\tfrac_type -i --help\tDisplays imag info\t\tj\n");
	ft_printf("\tfrac_type -z --help\tDisplays zoom info\t\tm && j\n");
	ft_printf("\tfrac_type -n --help\tDisplays iter info\t\tm\n");
	ft_printf("\tfrac_type -c --help\tDisplays center info\t\tm\n");
	ft_printf("\tfrac_type    --help\tDisplays fractal info\t\tm && j\n");
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

void	valid(int argc, char **argv)
{
	(void)argc;
	if (**argv != '-')
		usage();
	if (**argv == '-' && !char_is(*(*argv + 1), "dferiznec"))
		usage();
}

/*
 * First arg MUST be fractal type
 * */
t_err	parse_args(int argc, char **argv, t_fract *f)
{
	t_opt	opt;

	argv++;
	type_check(argc, argv, f);
	argv++;
	while (*argv)
	{
		valid(argc, argv);
		opt.cnt = 0;
		render_check(argc, argv, f, &opt); 
		func_check(argc, argv, f, &opt);
		exp_check(argc, argv, f, &opt);
		zoom_check(argc, argv, f, &opt);
		iter_check(argc, argv, f, &opt);
		center_check(argc, argv, f, &opt);
		ri_check(argc, argv, f, &opt);
		argv += opt.cnt;
	}
	return (OK);
}
