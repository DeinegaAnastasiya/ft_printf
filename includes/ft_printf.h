/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:02:58 by poatmeal          #+#    #+#             */
/*   Updated: 2020/07/29 12:07:48 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# define BIG_BUFF			60000
# define BUFF_2				1000

typedef struct				s_dbl
{
	unsigned long long		s: 1;
	unsigned long long		e: 11;
	unsigned long long		m: 52;
}							t_dbl;

typedef union				u_mask
{
	t_dbl					bits;
	long double				num;
}							t_mask;

#endif