/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:01:00 by poatmeal          #+#    #+#             */
/*   Updated: 2020/07/31 17:41:05 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

void			plus_number_2(t_buf *buf)
{
	size_t				i;
	long long int		x;
	long long int		coef;

	i = 0;
	coef = 0;
	while (buf->wh_num[BIG_BUFF - i] != -1 || buf->pow_2[BIG_BUFF - i] != -1)
	{
		if (buf->wh_num[BIG_BUFF - i] == -1)
			x = buf->pow_2[BIG_BUFF - i];
		else if (buf->pow_2[BIG_BUFF - i] == -1)
			x = buf->wh_num[BIG_BUFF - i];
		else
			x = buf->wh_num[BIG_BUFF - i] + buf->pow_2[BIG_BUFF - i];
		buf->wh_num[BIG_BUFF - i] = (x + coef) % 10;
		if (x + coef > 9)
			coef = 1;
		else
			coef = 0;
		i++;
	}
}

void			count_nul(t_buf *buf, long long int nul)
{
	int					i;

	i = 0;
	while (buf->pow_5[BIG_BUFF - i] != -1 && nul > 0)
	{
		i++;
		nul--;
	}
	while (nul > 0)
	{
		buf->pow_5[BIG_BUFF - i] = 0;
		i++;
		nul--;
	}
}

void			plus_number_5(t_buf *buf, long long int nul)
{
	size_t				i;
	long long int		x;
	long long int		coef;

	i = 0;
	coef = 0;
	count_nul(buf, nul);
	while (buf->div_num[BIG_BUFF - i] != -1 || buf->pow_5[BIG_BUFF - i] != -1)
	{
		if (buf->div_num[BIG_BUFF - i] == -1)
			x = buf->pow_5[BIG_BUFF - i];
		else if (buf->pow_5[BIG_BUFF - i] == -1)
			x = buf->div_num[BIG_BUFF - i];
		else
			x = buf->div_num[BIG_BUFF - i] + buf->pow_5[BIG_BUFF - i];
		buf->div_num[BIG_BUFF - i] = (x + coef) % 10;
		if (x + coef > 9)
			coef = 1;
		else
			coef = 0;
		i++;
	}
}

void			take_to_5(t_buf *buf, int pow, long long int nul)
{
	long long int		x;
	int					y;
	long long int		coef;

	buf->pow_5[BIG_BUFF] = 5;
	while (pow > 1)
	{
		y = 0;
		x = buf->pow_5[BIG_BUFF] * 5;
		buf->pow_5[BIG_BUFF] = x % 10;
		coef = x / 10;
		while (buf->pow_5[BIG_BUFF - (++y)] != -1 || coef > 0)
		{
			if (buf->pow_5[BIG_BUFF - y] != -1)
			{
				x = buf->pow_5[BIG_BUFF - y] * 5 + coef;
				buf->pow_5[BIG_BUFF - y] = x % 10;
				coef = x / 10;
			}
			else
			{
				buf->pow_5[BIG_BUFF - y] = coef;
				coef = coef / 10;
			}
		}
		pow--;
	}
	plus_number_5(buf, nul);
	ft_memset(buf->pow_5, -1, BIG_BUFF + 1);
}

void			take_to_2(t_buf *buf, int pw)
{
	long long int		x;
	int					y;
	long long int		coef;

	if (pw == 0)
		buf->pow_2[BIG_BUFF] = 1;
	else
		buf->pow_2[BIG_BUFF] = 2;
	while (pw > 1)
	{
		y = 0;
		x = buf->pow_2[BIG_BUFF] * 2;
		buf->pow_2[BIG_BUFF] = x % 10;
		coef = x / 10;
		while (buf->pow_2[BIG_BUFF - (++y)] != -1 || coef > 0)
		{
			if (buf->pow_2[BIG_BUFF - y] != -1)
			{
				x = buf->pow_2[BIG_BUFF - y] * 2 + coef;
				buf->pow_2[BIG_BUFF - y] = x % 10;
				coef = x / 10;
			}
			else
			{
				buf->pow_2[BIG_BUFF - y] = coef;
				coef = coef / 10;
			}
		}
		pw--;
	}
	plus_number_2(buf);
	ft_memset(buf->pow_2, -1, BIG_BUFF + 1);
}

void			mem_alloc(t_buf *buf)
{
	buf->wh_num = (char *)ft_memalloc(sizeof(char) * BIG_BUFF + 1);
	ft_memset(buf->wh_num, -1, BIG_BUFF);
	buf->div_num = (char *)ft_memalloc(sizeof(char) * BIG_BUFF + 1);
	ft_memset(buf->div_num, -1, BIG_BUFF);
	buf->pow_2 = (char *)ft_memalloc(sizeof(char) * BIG_BUFF + 1);
	ft_memset(buf->pow_2, -1, BIG_BUFF);
	buf->pow_5 = (char *)ft_memalloc(sizeof(char) * BIG_BUFF + 1);
	ft_memset(buf->pow_5, -1, BIG_BUFF);
}

void			print(t_buf *buf)
{
	int					i;

	i = 0;
	while (buf->wh_num[i] == -1)
		i++;
	while (i < BIG_BUFF + 1)
	{
		ft_putchar(buf->wh_num[i] + 48);
		i++;
	}
	ft_putchar('.');
	i = 0;
	while (buf->div_num[i] == -1)
		i++;
	while (i < BIG_BUFF + 1)
	{
		ft_putchar(buf->div_num[i] + 48);
		i++;
	}
	ft_putchar('\n');
}

void			conversion(t_mask bits, t_buf *buf)
{
	int					e;
	int					i;

	i = 0;
	mem_alloc(buf);
	e = bits.bits.e - 16383;
	while (i < 64)
	{
		if ((bits.bits.m >> (63 - i)) & 1)
		{
			if (e - i >= 0)
			{
				take_to_2(buf, e - i);
			}
			else if (e - i < 0)
			{
				take_to_5(buf, -(e - i), -(e - i));
			}
		}
		i++;
	}
	print(buf);
}

void			ft_printf(long double num)
{
	t_mask				bit_num;
	t_buf				*buf;

	buf = (t_buf *)ft_memalloc(sizeof(t_buf));
	bit_num.num = num;
	conversion(bit_num, buf);
}

int				main(void)
{
	ft_printf(55077.255);
	printf("%.52Lf\n", 55077.255l);
	return (0);
}
