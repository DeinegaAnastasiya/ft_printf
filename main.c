/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:23:10 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/04 11:15:31 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int				main(void)
{
	long double	i;

	i = 3.03;
	print_f(i);
	printf("%.55Lf\n", i);
	return (0);
}
