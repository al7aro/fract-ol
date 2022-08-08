/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:35:02 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/08 15:05:05 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "parser.h"
#include "libft.h"
#include "fractol.h"
#include "ft_printf.h"

void	render_check(int argc, char **argv, t_fract *f, t_opt *opt)
{
	(void)argc;
	if (**argv == '-' && *(*argv + 1) == 'd' && ft_strlen(*argv + 1) == 1)
	{
		if (!ft_strisdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				render_usage();
			else
				usage();
		}
		f->render_factor = ft_atoi(*(argv + 1));
		opt->D = 2;
		opt->cnt = opt->D;
	}
}

void	render_usage(void)
{
	ft_printf("usage: fract-ol fractal_type");
	ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n\n");
	ft_printf("Specify render detail.\n");
	ft_printf("Default: 1\n");
	ft_printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
