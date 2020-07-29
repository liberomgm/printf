/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:41:16 by hurek             #+#    #+#             */
/*   Updated: 2020/07/29 17:01:40 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_nbr(int n, t_args *parsed)
{
	unsigned int	i;
	char			res;

	i = 0;
	if (n < 0)
		i = n * -1;
	else
		i = n;
	if (i > 9)
		ft_print_nbr(i / 10, parsed);
	res = i % 10 + 48;
	parsed->len += write(1, &res, 1);
}

void	ft_print_nchar(char c, int number, t_args *parsed)
{
	while (number)
	{
		parsed->len += write(1, &c, 1);
		number--;
	}
}

void	ft_print_base(size_t number, int reg, size_t base, t_args *parsed)
{
	size_t num;

	if (!number)
	{
		parsed->len += write(1, "0", 1);
		return ;
	}
	if (number > (base - 1))
		ft_print_base((number / base), reg, base, parsed);
	num = number % base;
	if ((num >= 10) && (num <= 15) && (reg == 0))
		ft_print_nchar((char)num + 87, 1, parsed);
	else if ((num >= 10) && (num <= 15) && (reg == 1))
		ft_print_nchar((char)num + 55, 1, parsed);
	else if ((num >= 1) && (num <= 9))
		ft_print_nchar((char)num + 48, 1, parsed);
}
