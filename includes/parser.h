/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:58:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/07 19:23:17 by alopez-g         ###   ########.fr       */
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

t_err	usage();
t_err	type_usage(t_err err);
void	render_usage();
void	zoom_usage();
void	iter_usage();
void	center_usage();
void	ri_usage();
void	exp_usage();
void	func_usage();
t_err	type_check(int argc, char **argv, t_fract *f);
t_err	render_check(int argc, char **argv, t_fract *f);
t_err	zoom_check(int argc, char **argv, t_fract *f);
t_err	iter_check(int argc, char **argv, t_fract *f);
t_err	center_check(int argc, char **argv, t_fract *f);
t_err	r_check(int argc, char **argv, t_fract *f);
t_err	i_check(int argc, char **argv, t_fract *f);
t_err	exp_check(int argc, char **argv, t_fract *f);
t_err	func_check(int argc, char **argv, t_fract *f);
t_err	parse_args(int argc, char **argv, t_fract *f);

#endif
