/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:50 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:14:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include <stdio.h>

void	iter_check(char **argv, t_fract *f, t_opt *opt)
{
	if (**argv == '-' && *(*argv + 1) == 'n')
	{
		if (*(*argv + 2) != 0)
			usage();
		if (!ft_strisdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				iter_usage();
			else
				usage();
		}
		f->it = ft_atoi(*(argv + 1));
		if (f->it <= 0)
			usage();
		opt->n = 2;
		opt->cnt = opt->n;
	}
}

void	iter_usage(void)
{
	printf("usage: fract-ol fractal_type");
	printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	printf("Specify initial number of ITERATIONS to use when func is used\n");
	printf("Default: 100\n");
	printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
