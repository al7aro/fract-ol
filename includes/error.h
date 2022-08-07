/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:16:40 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/07 19:20:07 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRROR_H
# define ERRROR_H

typedef enum e_err
{
	INVALID_ARGUMENT,
	TYPE_USAGE,
	RENDER_USAGE,
	ZOOM_USAGE,
	ITER_USAGE,
	CENTER_USAGE,
	RI_USAGE,
	EXP_USAGE,
	FUNC_USAGE,

	MANDELBROT_USAGE,
	JULIA_USAGE,
	OK
}			t_err;

#endif
