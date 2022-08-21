/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:59:33 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/21 17:39:23 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycodes.h"
#include "fractol.h"
#include <math.h>

int	iter(int keycode, t_fract *f)
{
	if (keycode == PLUS)
		f->it += log10(f->zoom);
	else if (keycode == MINUS)
		f->it -= log10(f->zoom);
	else if (keycode == DEL)
		f->render_factor++;
	return (0);
}
