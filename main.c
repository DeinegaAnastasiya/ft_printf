/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:23:10 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/08 14:22:07 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				main(void)
{
	double	i;
	int		n;
	int		m;

	i = 1543.51456466;
	m = ft_printf(i);
	printf("\n");
	printf("%i", m);
	printf("\n");
	n = printf("% 020.8f", i);
	printf("\n");
	printf("%i\n", n);
	return (0);
}
