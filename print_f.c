/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:10:36 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/08 15:05:11 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			print_div(t_buf *buf, t_printf *get)
{
	int		i;

	ft_putchar('.');
	get->len++;
	i = 0;
	if (buf->div_num[i] == -1)
	{
		ft_putchar('0');
		get->len++;
	}
	while (buf->div_num[i] != -1 && i < BIG_BUFF + 1 && i < get->precis)
	{
		ft_putchar(buf->div_num[i] + 48);
		i++;
	}
	get->len += i;
}

void			print(t_buf *buf, t_printf *get)
{
	int		i;

	i = 0;
	if (get->sign == -1)
	{
		ft_putchar('-');
		get->len++;
	}
	while (buf->wh_num[i] == -1)
		i++;
	while (i < BIG_BUFF + 1)
	{
		ft_putchar(buf->wh_num[i] + 48);
		get->len++;
		i++;
	}
	if (get->precis != 0)
		print_div(buf, get);
	if (get->precis == 0 && get->fh == 1)
	{
		ft_putchar('.');
		get->len++;
	}
}

void			print_align(t_buf *buf, t_printf *get)
{
	int n;
	int i;

	i = 0;
	n = get->width - get->precis - 1;
	while (buf->wh_num[BIG_BUFF - i] != -1)
		i++;
	if (i < n)
	{
		check_plus_space(get);
		print(buf, get);
		while (i < n)
		{
			ft_putchar(' ');
			get->len++;
			i++;
		}
	}
}

void			print_f(t_buf *buf, t_printf *get)
{
	if (get->precis >= 0)
		ft_round(buf, get);
	if (get->fm == 1)
	{
		print_align(buf, get);
		return ;
	}
	if (get->width > 0)
		fill_width(buf, get);
	else if (get->fp == 1)
	{
		if (get->sign > 0)
		{
			ft_putchar('+');
			get->len++;
		}
	}
	else if (get->fp == 0 && get->fs == 1 && get->sign > 0)
	{
		ft_putchar(' ');
		get->len++;
	}
	print(buf, get);
}
