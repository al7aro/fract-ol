/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:35:02 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/06 18:20:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	render_check()
{
}

void	render_usage()
{
	ft_printf("usage: fract-ol fractal_type [-d render] [-f func] [-e exp] [-r real] [-i imag] [-z zoom] [-n iter] [-c centerX centerY]\n");
	ft_printf("Specify render detail.\n");
	ft_printf("Default: 1\n");
	ft_printf("\n\t--help\t\tDisplay more help");
}
