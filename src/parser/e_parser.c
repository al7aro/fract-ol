/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 13:37:37 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "error.h"
#include "fractol.h"
#include "ft_printf.h"

void	exp_check(int argc, char **argv, t_fract *f, t_opt *opt)
{
	(void)argc;
	if (**argv == '-' && *(*argv + 1) == 'e' && ft_strlen(*argv + 1) == 1)
	{
		if (!ft_strisdigit(*(argv + 1)) || *(*argv) == 48)
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				exp_usage();
			else
				usage();
		}
		f->exp = ft_atoi(*(argv + 1));
		opt->e = 2;
		opt->cnt = opt->e;
	}
}

void	exp_usage(void)
{
	ft_printf("usage: fract-ol fractal_type");
	ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("Specify N to use when func is used\n");
	ft_printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
