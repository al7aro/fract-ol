/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ri_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:54 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/07 18:54:00 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "error.h"
#include "fractol.h"
#include "ft_printf.h"

t_err	r_check(int argc, char **argv, t_fract *f)
{
	(void)argc;
	(void)f;
	if (**argv == '-' && *(*argv + 1) == 'r' && ft_strlen(*argv + 1) == 1)
	{
		if (!ft_strisfdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				ri_usage();
			else
				usage();
			return (INVALID_ARGUMENT);
		}
	}
	return (OK);
}

t_err	i_check(int argc, char **argv, t_fract *f)
{
	(void)argc;
	(void)f;
	if (**argv == '-' && *(*argv + 1) == 'i' && ft_strlen(*argv + 1) == 1)
	{
		if (!ft_strisfdigit(*(argv + 1)))
		{
			if (*(argv + 1) && !ft_strncmp(*(argv + 1), "--help", 6))
				ri_usage();
			else
				usage();
			return (INVALID_ARGUMENT);
		}
	}
	return (OK);
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
}
