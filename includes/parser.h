/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:58:55 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/25 03:09:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fractol.h"

typedef struct s_opt
{
	char	type;
	char	d;
	char	f;
	char	e;
	char	i;
	char	z;
	char	n;
	char	c;
	char	cnt;
}		t_opt;

void	usage(void);
void	type_usage(void);
void	render_usage(void);
void	zoom_usage(void);
void	iter_usage(void);
void	center_usage(void);
void	ri_usage(void);
void	exp_usage(void);
void	type_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	render_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	zoom_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	iter_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	center_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	ri_check(int argc, char **argv, t_fract *f, t_opt *opt);
void	exp_check(int argc, char **argv, t_fract *f, t_opt *opt);
int		parse_args(int argc, char **argv, t_fract *f);

#endif
