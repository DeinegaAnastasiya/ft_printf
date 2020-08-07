/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:10:36 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/07 21:35:31 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			print(t_buf *buf, t_print *get)
{
	int					i;

	i = 0;
	if (get->sign == -1)
	{
		ft_putchar('-');
		get->out_ch++;
	}
	while (buf->wh_num[i] == -1)
		i++;
	while (i < BIG_BUFF + 1)
	{
		ft_putchar(buf->wh_num[i] + 48);
		get->out_ch++;
		i++;
	}
	if (get->prec != 0)
	{
		ft_putchar('.');
		get->out_ch++;
		i = 0;
		if (buf->div_num[i] == -1)
		{
			ft_putchar('0');
			get->out_ch++;
		}
		while (buf->div_num[i] != -1 && i < BIG_BUFF + 1 && i < get->prec)
		{
			ft_putchar(buf->div_num[i] + 48);
			i++;
		}
		get->out_ch += i;
	}
	if (get->prec == 0 && get->oct == 1)
	{
		ft_putchar('.');
		get->out_ch++;
	}
}

void			change_whole(t_buf *buf)
{
	int		j;

	j = 0;
	if (buf->wh_num[BIG_BUFF] + 1 > 9)
	{
		while (buf->wh_num[BIG_BUFF - j] + 1 > 9)
		{
			buf->wh_num[BIG_BUFF - j] = 0;
			j++;
		}
	}
	if (buf->wh_num[BIG_BUFF - j] == -1)
		buf->wh_num[BIG_BUFF - j] = 1;
	else
		buf->wh_num[BIG_BUFF - j] = buf->wh_num[BIG_BUFF - j] + 1;
}

void			change_div(t_buf *buf, int i)
{
	if (buf->div_num[i] + 1 > 9)
	{
		while (i >= 0 && buf->div_num[i] + 1 > 9)
		{
			buf->div_num[i] = 0;
			i--;
		}
	}
	if (i < 0)
		change_whole(buf);
	else
		buf->div_num[i] = buf->div_num[i] + 1;
}

void			check_round(t_buf *buf, int i)
{
	while (i < BIG_BUFF && buf->div_num[i] == 0)
		i++;
	if (i < BIG_BUFF && buf->div_num[i] != -1)
		change_whole(buf);
}

void			check_round_div(t_buf *buf, int i)
{
	int j;
	
	j = i;
	while (i < BIG_BUFF && buf->div_num[i] == 0)
		i++;
	if (i < BIG_BUFF && buf->div_num[i] != -1)
		change_div(buf, j - 2);
}

void			ft_round(t_buf *buf, t_print *get)
{
	int i;
	int j;

	j = 0;
	i = get->prec;
	if (i == 0)
	{
		if (buf->div_num[i] > 5)
			change_whole(buf);
		else if (buf->div_num[i] == 5 && buf->div_num[i + 1] == -1)
		{
			if (buf->wh_num[BIG_BUFF] % 2 != 0)
				change_whole(buf);
		}
		else if (buf->div_num[i] == 5 && buf->div_num[i + 1] != -1)
			check_round(buf, i + 1);
	}
	else
	{
		if (buf->div_num[i] > 5)
			change_div(buf, i - 1);
		else if (buf->div_num[i] == 5 && buf->div_num[i + 1] == -1)
		{
			if (buf->div_num[i - 1] % 2 != 0)
				change_div(buf, i - 1);
		}
		else if (buf->div_num[i] == 5 && buf->div_num[i + 1] != -1)
			check_round_div(buf, i + 1);
	}
}

int			fill_plus(t_buf *buf, t_print *get, int i)
{
	if (get->sign < 0)
	{
		buf->wh_num[BIG_BUFF - i] = -3;
		i++;
	}
	else if (get->plus == 1 && get->sign > 0)
	{
		buf->wh_num[BIG_BUFF - i] = -5;
		i++;
	}
	return (i);
}

void			fill_width(t_buf *buf, t_print *get)
{
	int n;
	int i;
	char val;

	i = 0;
	n = get->width - get->prec - 1;
	if (get->plus == 0 && get->space == 1 && get->sign > 0 && i < n)
		n = get->width - get->prec - 2;
	val = -16;
	if (get->width_zero == 1)
		val = 0;
	while (buf->wh_num[BIG_BUFF - i] != -1)
		i++;
	i = fill_plus(buf, get, i);
	while (i < n)
	{
		buf->wh_num[BIG_BUFF - i] = val;
		i++;
	}
	if (get->plus == 0 && get->space == 1 && get->sign > 0)
	{
		buf->wh_num[BIG_BUFF - i] = -16;
		i++;
	}
}

void			check_plus_space(t_print *get)
{
	if (get->plus == 1 && get->sign < 0)
	{
		ft_putchar('-');
		get->out_ch++;
	}
	else if (get->plus == 1 && get->sign > 0)
	{
		ft_putchar('+');
		get->out_ch++;
	}
	else if (get->plus == 0 && get->space == 1 && get->sign > 0)
	{
		ft_putchar(' ');
		get->out_ch++;
	}
}

void			print_align(t_buf *buf, t_print *get)
{
	int n;
	int i;

	i = 0;
	n = get->width - get->prec - 1;
	while (buf->wh_num[BIG_BUFF - i] != -1)
		i++;
	if (i < n)
	{
		check_plus_space(get);
		print(buf, get);
		while (i < n)
		{
			ft_putchar(' ');
			get->out_ch++;
			i++;
		}
	}
}

void				print_f(t_buf *buf, t_print *get)
{
	if (get->prec >= 0)
		ft_round(buf, get);
	if (get->align == 1)
	{
		print_align(buf, get);
		return ;
	}
	if (get->width > 0)
		fill_width(buf, get);
	else if (get->plus == 1)
	{
		if (get->sign > 0)
		{
			ft_putchar('+');
			get->out_ch++;
		}
	}
	else if (get->plus == 0 && get->space == 1 && get->sign > 0)
	{
		ft_putchar(' ');
		get->out_ch++;
	}
	print(buf, get);
}

