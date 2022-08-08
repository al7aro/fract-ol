/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:58:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/08 13:10:01 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "fractol.h"
#include "error.h"

typedef struct s_opt
{
	char	D;
	char	F;
	char	E;
	char	I;
	char	Z;
	char	N;
	char	C;
	char	cnt;
}		t_opt;

void	usage();
void	type_usage();
void	render_usage();
void	zoom_usage();
void	iter_usage();
void	center_usage();
void	ri_usage();
void	exp_usage();
void	func_usage();

void	type_check(int argc, char **argv, t_fract *f);
void	render_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	zoom_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	iter_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	center_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	ri_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	exp_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	func_check(int argc, char **argv, t_fract *f, t_opt *opt);

t_err	parse_args(int argc, char **argv, t_fract *f);

#endif
