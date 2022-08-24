/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:20:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/24 02:37:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "fractol.h"

int	hook_key_pressed(int keycode, void *param);
int	hook_mouse_pressed(int button, int x, int y, void *param);
int	hook_mouse_move(int x, int y, void *param);
int	move(int keycode, t_fract *f);
int	visual(int keycode, t_fract *f);
int	iter(int keycode, t_fract *f);
int	menu(int keycode, t_fract *f);
int	type(int keycode, t_fract *f);
int	mouse_move(int x, int y, t_fract *f);
int	mouse_scroll(int button, int x, int y, t_fract *f);
int	mouse_type(int button, int x, int y, t_fract *f);

#endif
