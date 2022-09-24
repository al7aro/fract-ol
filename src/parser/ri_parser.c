/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ri_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:54 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:14:10 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include <stdio.h>

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
		f->center = (t_vec2){{f->julia_init.x}, {f->julia_init.y}};
		f->mouse_pos = (t_vec2){{f->center.x}, {f->center.y}};
		opt->i = 3;
		opt->cnt = opt->i;
	}
}

void	ri_usage(void)
{
	printf("usage: fract-ol fractal_type");
	printf(" [-d render] [-f func] [-e exp] [-r real]");
	printf(" [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	printf("Set initial conditions of a Julia like fractal\n");
	printf("\t-r\t\tSet real part\n");
	printf("\t-i\t\tSet imaginary part\n");
	printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
