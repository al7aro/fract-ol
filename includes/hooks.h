/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:20:06 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/21 03:29:47 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

int	key_pressed(int keycode, void *param);
int	mouse_pressed(int button, int x, int y, void *param);
int	mouse_move(int x, int y, void *param);

#endif
