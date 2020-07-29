/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:01:00 by poatmeal          #+#    #+#             */
/*   Updated: 2020/07/29 15:49:34 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

char	*plus_number_2(char *big_num, char *pow)
{
	size_t	i;
	int		x;
	int		coef;

	i = 0;
	coef = 0;
	while (big_num[BIG_BUFF - i] != -1 || pow[BIG_BUFF - i] != -1)
	{
		x = (big_num[BIG_BUFF - i] - 48) + (pow[BIG_BUFF - i] - 48);
		big_num[BIG_BUFF - i] = (x + coef) % 10;
		if (x + coef > 9)
			coef = 1;
		else
			coef = 0;
		i++;
	}
	return (big_num);
}

char	*count_nul(char *pow, int nul)
{
	int i;

	i = 0;
	while (pow[BIG_BUFF - i] != -1 && nul > 0)
	{
		i++;
		nul--;
	}
	while (nul > 0)
	{
		pow[BIG_BUFF - i] = '0';
		i++;
		nul--;
	}
	return (pow);
}

char	*plus_number_5(char *big_num, char *pow, int nul)
{
	size_t	i;
	int		x;
	int		coef;

	i = 0;
	coef = 0;
	pow = count_nul(pow, nul);
	while (big_num[BIG_BUFF - i] != -1 || pow[BIG_BUFF - i] != -1)
	{
		x = (big_num[BIG_BUFF - i] - 48) + (pow[BIG_BUFF - i] - 48);
		big_num[BIG_BUFF - i] = (x + coef) % 10;
		nul--;
		if (x + coef > 9)
			coef = 1;
		else
			coef = 0;
		i++;   
	}
	return (big_num);
}

char	*take_to_5(char *big_num, int pow, int nul)
{
	char	pow_5[BIG_BUFF + 1];
	int		x;
	int		y;
	int		coef;

	y = 0;
	ft_memset(pow_5, -1, BIG_BUFF);
	pow_5[BIG_BUFF] = '5';
	while (pow > 0)
	{
		x = (pow_5[BIG_BUFF] - 48)  * 5;
		pow_5[BIG_BUFF] = (x % 10) + 48;
		coef = x/10;
		while (pow_5[BIG_BUFF - (++y)] != -1 || coef > 0)
		{
			if (pow_5[BIG_BUFF - y] != -1)
			{
				x = ((pow_5[BIG_BUFF - y] - 48)  * 5) + coef;
				pow_5[BIG_BUFF - y] = (x % 10) + 48;
				coef = x / 10;
			}
			else
			{
				pow_5[BIG_BUFF - y] = coef + 48;
				coef = coef / 10;
			}
			
		}
		pow--;
		y = 0;
	}
	big_num = plus_number_5(big_num, pow_5, nul);
	return (big_num);
}

char	*take_to_2(char *big_num, int pow)
{
	char	pow_2[BIG_BUFF + 1];
	int		x;
	int		y;
	int		coef;
	
	y = 0;
	ft_memset(pow_2, -1, BIG_BUFF);
	pow_2[BIG_BUFF] = '2';
	while (pow > 0)
	{
		x = (pow_2[BIG_BUFF] - 48)  * 2;
		pow_2[BIG_BUFF] = (x % 10) + 48;
		coef = x/10;
		while (pow_2[BIG_BUFF - (++y)] != -1 || coef > 0)
		{
			if (pow_2[BIG_BUFF - y] != -1)
			{
				x = ((pow_2[BIG_BUFF - y] - 48)  * 2) + coef;
				pow_2[BIG_BUFF - y] = (x % 10) + 48;
			}
			else
				pow_2[BIG_BUFF - y] = coef + 48;
			coef = x / 10;
		}
		pow--;
		y = 0;
	}
	big_num = plus_number_2(big_num, pow_2);
	return (big_num);
}

void	conversion(t_mask bits)
{
	char	*wh_num;
	char	*div_num;
	int		e;
	int		i;

	i = 0;
	wh_num = (char *)ft_memalloc(sizeof(char) * BIG_BUFF + 1);
	div_num = (char *)ft_memalloc(sizeof(char) * BIG_BUFF + 1);
	ft_memset(wh_num, -1, BIG_BUFF);
	ft_memset(div_num, -1, BIG_BUFF);
	e = bits.bits.e - 16383;
	while (i < 64)
	{
		if ((bits.bits.m >> (63 - i)) & 1)
		{
			if (e - i >= 0)
				wh_num = take_to_2(wh_num, e - i);
			else if (e - i < 0)
				div_num = take_to_5(div_num, -(e - i), -(e - i));
		}
		i++;
		
	}
	i = 0;
	while (wh_num[i] == (-1))
	{
		
		i++;
	}
	while (wh_num[i] && )
	{
		ft_putchar(wh_num[i]);
		i++;
	}
	ft_putchar('.');
	i = 0;
	while (div_num[i] == (-1))
		i++;
	while (div_num[i] && )
	{
		ft_putchar(div_num[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_printf(long double num)
{
	t_mask	bit_num;

	bit_num.num = num;
	conversion(bit_num);
}

int	main()
{
	ft_printf(3.03);
	printf("%.30f\n", 3.03);
	return (0);
}