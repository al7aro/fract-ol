/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:14:27 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 14:07:53 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <math.h>

long double	ft_length(long double x, long double y)
{
	long double	l;

	l = sqrt(powl(x, 2) + powl(y, 2));
	return (l);
}
