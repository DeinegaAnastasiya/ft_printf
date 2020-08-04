/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:01:00 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/04 13:24:36 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

void			print(t_buf *buf, int sign)
{
	int					i;

	i = 0;
	if (sign == -1)
		ft_putchar('-');
	while (buf->wh_num[i] == -1)
		i++;
	while (i < BIG_BUFF + 1)
	{
		ft_putchar(buf->wh_num[i] + 48);
		i++;
	}
	ft_putchar('.');
	i = 0;
	if (buf->div_num[i] == -1)
		ft_putchar('0');
	while (buf->div_num[i] != -1)
	{
		ft_putchar(buf->div_num[i] + 48);
		i++;
	}
	ft_putchar('\n');
	
}

void			*free_print(t_buf *buf)
{
	if (!buf)
		return (NULL);
	free(buf->div_num);
	free(buf->wh_num);
	free(buf->pow_2);
	free(buf->pow_5);
	//free(buf);
	buf = NULL;
	return (buf);
}

void			conversion(t_mask bits, t_buf *buf)
{
	int					e;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	if (bits.bits.s == 1)
		sign = -sign;
	e = bits.bits.e - 16383;
	while (i < 64)
	{
		if ((bits.bits.m >> (63 - i)) & 1)
		{
			if (e - i >= 0)
				take_to_2(buf, e - i);
			else if (e - i < 0)
				take_to_5(buf, -(e - i), -(e - i));
		}
		i++;
	}
	print(buf, sign);
}

void			print_f(long double num)
{
	t_mask				bit_num;
	t_buf				*buf;

	buf = (t_buf *)ft_memalloc(sizeof(t_buf));
	mem_alloc(buf);
	bit_num.num = num;
	conversion(bit_num, buf);
	free_print(buf);
}
