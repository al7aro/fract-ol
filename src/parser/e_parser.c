/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:14:33 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include <stdio.h>

void	exp_check(char **argv, t_fract *f, t_opt *opt)
{
	if (**argv == '-' && *(*argv + 1) == 'e')
	{
		if (*(*argv + 2) != 0)
			usage();
		if (!ft_strisdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				exp_usage();
			else
				usage();
		}
		f->exp = ft_atoi(*(argv + 1));
		if (f->exp <= 0)
			usage();
		opt->e = 2;
		opt->cnt = opt->e;
	}
}

void	exp_usage(void)
{
	printf("usage: fract-ol fractal_type");
	printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	printf("Specify N to use when func is used\n");
	printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
