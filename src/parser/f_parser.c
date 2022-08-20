/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:35:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 13:37:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_printf.h"
#include "libft.h"
#include "fractol.h"
#include "ft_printf.h"
#include "error.h"

void	func_check(int argc, char **argv, t_fract *f, t_opt *opt)
{
	(void)argc;
	(void)f;
	if (**argv == '-' && *(*argv + 1) == 'f' && ft_strlen(*argv + 1) == 1)
	{
		if (!ft_strisalpha(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				func_usage();
			else
				usage();
		}
		ft_printf("Check -f");
		opt->f = 2;
		opt->cnt = opt->f;
	}
}

void	func_usage(void)
{
	ft_printf("usage: fract-ol fractal_type");
	ft_printf(" [-d render] [-f func] [-e exp] [-r real] [-i imag]");
	ft_printf(" [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify the function to use to calculate fractal, limited to:\n");
	ft_printf("\tznc\t\tz^n + c. Default n = 2\n");
	ft_printf("\n\t--help\t\tDisplay more help");
	exit(0);
}
