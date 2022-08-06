/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:58:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/06 18:22:28 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "fractol.h"
#include "error.h"

typedef enum e_opt
{
	D = 0,
	F = 1,
	E = 2,
	R = 3,
	I = 4,
	Z = 5,
	N = 6,
	C = 7
}		t_opt;

void	usage();
void	render_usage();
void	render_check(t_fract *f);
void	zoom_usage();
void	zoom_usage(t_fract *f);
void	iter_usage();
void	iter_check(t_fract *f);
void	center_usage();
void	center_check(t_fract *f);
void	ri_usage();
void	ri_check(t_fract *f);
void	exp_usage();
void	exp_check(t_fract *f);
void	func_usage();
void	func_check(t_fract *f);
t_err	parse_args(int argc, char **argv, t_fract *f);

#endif
