/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:35:20 by alopez-g          #+#    #+#             */
/*   Updated: 2022/09/24 14:13:50 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include <stdio.h>

void	zoom_check(char **argv, t_fract *f, t_opt *opt)
{
	if (**argv == '-' && *(*argv + 1) == 'z')
	{
		if (*(*argv + 2) != 0)
			usage();
		if (!ft_strisdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				zoom_usage();
			else
				usage();
		}
		f->zoom = ft_atoi(*(argv + 1));
		if (f->zoom <= 0)
			usage();
		opt->z = 2;
		opt->cnt = opt->z;
	}
}

void	zoom_usage(void)
{
	printf("usage: fract-ol fractal_type");
	printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	printf("Specify initial ZOOM\n");
	printf("Default: 100\n");
	printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
