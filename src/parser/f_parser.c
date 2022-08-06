/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:35:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/06 18:20:31 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	func_check()
{
}

void	func_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify the function to use to calculate fractal, limited to:\n");
	ft_printf("\tznc\t\tz^n + c. Default n = 2\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}
