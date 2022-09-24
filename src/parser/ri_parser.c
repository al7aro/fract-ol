/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ri_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:54 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 13:39:06 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include "ft_printf.h"

void	ri_check(char **argv, t_fract *f, t_opt *opt)
{
	if (**argv == '-' && *(*argv + 1) == 'i')
	{
		if (*(*argv + 2) != 0)
			usage();
		if (!ft_strisfdigit(*(argv++ + 1)) || !ft_strisfdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				ri_usage();
			else
				usage();
		}
		if (!(**argv) || (**argv && !(**(argv + 1))))
			usage();
		f->julia_init.r = ft_atof(*(argv));
		if (!*(argv + 1))
			usage();
		f->julia_init.i = ft_atof(*(argv + 1));
		opt->i = 3;
		opt->cnt = opt->i;
	}
	opt->i = 0;
}

void	ri_usage(void)
{
	ft_printf("usage: fract-ol fractal_type");
	ft_printf(" [-d render] [-f func] [-e exp] [-r real]");
	ft_printf(" [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("Set initial conditions of a Julia like fractal\n");
	ft_printf("\t-r\t\tSet real part\n");
	ft_printf("\t-i\t\tSet imaginary part\n");
	ft_printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
