/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:15:41 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/29 21:23:14 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "keycodes.h"

int	key_pressed(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(0);
	return (0);
}
