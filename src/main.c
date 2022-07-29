/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:12:48 by alopez-g          #+#    #+#             */
/*   Updated: 2022/07/29 02:17:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	(void)mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	mlx_loop(mlx);
}

