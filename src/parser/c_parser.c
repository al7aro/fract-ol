/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:37 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:14:58 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include <stdio.h>

void	center_check(char **argv, t_fract *f, t_opt *opt)
{
	if (**argv == '-' && *(*argv + 1) == 'c')
	{
		if (*(*argv + 2) != 0)
			usage();
		if (!ft_strisfdigit(*(argv++ + 1)) || !ft_strisfdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				center_usage();
			else
				usage();
		}
		if (!(**argv) || (**argv && !(**(argv + 1))))
			usage();
		f->center.x = ft_atof(*(argv));
		if (!*(argv + 1))
			usage();
		f->center.y = ft_atof(*(argv + 1));
		f->mouse_pos = (t_vec2){{f->center.x}, {f->center.y}};
		opt->c = 3;
		opt->cnt = opt->c;
	}
}

void	center_usage(void)
{
	printf("usage: fract-ol fractal_type");
	printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	printf("Specify inital CENTER of image to use when func is used\n");
	printf("Default: [0, 0]\n");
	printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
