/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:54:58 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/07 19:44:51 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"
#include "libft.h"
#include "error.h"
#include "parser.h"

t_err	usage(void)
{
	ft_printf("usage: fract-ol fractal_type ");
	ft_printf("[-d render] [-f func] [-e exp] \n[-r real] ");
	ft_printf("[-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Options:\n");
	ft_printf("Each of the following options varies depending");
	ft_printf(" on fractal_type\n");
	ft_printf("\tfractals --help\t\t\tDisplays available fractal_type\n");
	ft_printf("\tfractal_type -d --help\t\tDisplays render_factor info\n");
	ft_printf("\tfractal_type -f --help\t\tDisplays func info\n");
	ft_printf("\tfractal_type -e --help\t\tDisplays exp info\n");
	ft_printf("\tfractal_type -r --help\t\tDisplays real info\n");
	ft_printf("\tfractal_type -i --help\t\tDisplays imag info\n");
	ft_printf("\tfractal_type -z --help\t\tDisplays zoom info\n");
	ft_printf("\tfractal_type -n --help\t\tDisplays iter info\n");
	ft_printf("\tfractal_type -c --help\t\tDisplays center info\n");
	ft_printf("\tfractal_type --help\t\tDisplays more info about");
	ft_printf(" a specyfic fractal\n");
	ft_printf("\n\t--help\t\t\t\tDisplays this menu\n");
	return (INVALID_ARGUMENT);
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

t_err	valid(int argc, char **argv)
{
	(void)argc;
	if (**argv != '-')
		return (INVALID_ARGUMENT);
	if (**argv == '-' && !char_is(*(*argv + 1), "dferiznec"))
		return (INVALID_ARGUMENT);
	return (OK);
}

/*
 * First arg MUST be fractal type
 * */
t_err	parse_args(int argc, char **argv, t_fract *f)
{
	t_err	err;

	argv++;
	err = type_check(argc, argv, f);
	if (err == INVALID_ARGUMENT)
		return (usage());
	else if (err != OK) 
		return (type_usage(err));
	argv++;
	while (*argv)
	{
		if (valid(argc, argv) != OK)
		{
			usage();
			return (INVALID_ARGUMENT);
		}
		if (render_check(argc, argv, f) != OK
			|| func_check(argc, argv, f) != OK
			|| exp_check(argc, argv, f) != OK
			|| zoom_check(argc, argv, f) != OK
			|| iter_check(argc, argv, f) != OK
			|| center_check(argc, argv, f) != OK
			|| r_check(argc, argv, f) != OK
			|| i_check(argc, argv, f) != OK)
			return (INVALID_ARGUMENT);
		argv += 2;
	}
	return (OK);
}
