/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:31:45 by alopez-g          #+#    #+#             */
/*   Updated: 2022/08/20 18:26:59 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_ftoa(long double, int);

int	main(void)
{
	char	*str;
	
	str = ft_ftoa(-10.123456, 9);
	ft_printf("%s", str);
	system("leaks test");
	return (0);
}
