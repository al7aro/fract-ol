/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:34:50 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/06 18:20:44 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	iter_check()
{
}

void	iter_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify initial number of ITERATIONS to use when func is used\n");
	ft_printf("Default: 100\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}
