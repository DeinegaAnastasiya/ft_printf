/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:02:58 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/04 10:40:53 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# define BIG_BUFF			60000
# define BUFF_2				1000

typedef struct				s_dbl
{
	unsigned long long		m: 64;
	unsigned long long		e: 15;
	unsigned long long		s: 1;
}							t_dbl;

typedef union				u_mask
{
	t_dbl					bits;
	long double				num;
}							t_mask;

typedef	struct				s_buf
{
	char					*wh_num;
	char					*div_num;
	char					*pow_2;
	char					*pow_5;
}							t_buf;

void						print_f(long double num);
void						take_to_2(t_buf *buf, int pw);
void						take_to_5(t_buf *buf, int pow, int nul);

#endif
