/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:32:31 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 18:33:07 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(long double num, int prc)
{
	char			*str_num;
	char			*aux;
	char			*f_aux;
	long double		f_part;

	str_num = ft_itoa((int)num);
	num = num * ((num < 0) * -1 + !(num < 0) * 1);
	f_part = num - (int)num;
	aux = ft_strjoin(str_num, ".");
	free(str_num);
	while (prc--)
	{
		f_part = f_part * (long double)10.0;
		if (!((int)f_part))
		{
			str_num = aux;
			aux = ft_strjoin(aux, "0");
			free(str_num);
		}
	}
	f_aux = ft_uitoa((int)f_part);
	str_num = ft_strjoin(aux, f_aux);
	free(aux);
	free(f_aux);
	return (str_num);
}
