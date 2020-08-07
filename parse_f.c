/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:01:00 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/07 21:33:22 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			alloc_pf(t_print *get)
{
	get->align = 0;
	get->L_l = 0;
	get->oct = 0;
	get->out_ch = 0;
	get->plus = 0;
	get->prec = 8;
	get->space = 1;
	get->width = 20;
	get->width_zero = 1;
}

int				ft_printf(double num)
{
	t_print			get;

	alloc_pf(&get);
	init_f(num, &get);
	return (get.out_ch);
}
