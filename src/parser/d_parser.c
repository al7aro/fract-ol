/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:35:02 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:14:38 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include <stdio.h>

void	render_check(char **argv, t_fract *f, t_opt *opt)
{
	if (**argv == '-' && *(*argv + 1) == 'd')
	{
		if (*(*argv + 2) != 0)
			usage();
		if (!ft_strisdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				render_usage();
			else
				usage();
		}
		f->render_factor = ft_atoi(*(argv + 1));
		if (f->render_factor <= 0)
			usage();
		opt->d = 2;
		opt->cnt = opt->d;
	}
}

void	render_usage(void)
{
	printf("usage: fract-ol fractal_type");
	printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	printf("Specify render detail.\n");
	printf("Default: 1\n");
	printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
