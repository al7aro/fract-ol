/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ri_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:54 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/06 18:21:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	r_check()
{
}

void	i_check()
{
}

void	ri_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Set initial conditions of a Julia like fractal\n");
	ft_printf("\t-r\t\tSet real part\n");
	ft_printf("\t-i\t\tSet imaginary part\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}
