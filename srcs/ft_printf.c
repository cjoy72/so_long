/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:00:07 by cbaroi            #+#    #+#             */
/*   Updated: 2024/05/06 16:48:11 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	pf_putnbr(int nbr, size_t *count)
{
	if (nbr < 0)
	{
		pf_putchar('-', count);
		if (nbr == -2147483648)
		{
			pf_putstr("2147483648", count);
			return ;
		}
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		pf_putnbr(nbr / 10, count);
		nbr = nbr % 10;
	}
	pf_putchar((nbr + '0'), count);
}

void	pf_putstr(char *str, size_t *count)
{
	int	i;

	i = -1;
	if (!str)
		pf_putstr("(null)", count);
	else
	{
		while (str[++i])
		{
			pf_putchar(str[i], count);
		}
	}
}

void	pf_putchar(char c, size_t *count)
{
	(*count) += write(1, &c, 1);
}

void	pf_flags(va_list args, char *str, size_t *count)
{
	if (*str == 'c')
		pf_putchar(va_arg(args, int), count);
	else if (*str == 's')
		pf_putstr(va_arg(args, char *), count);
	else if (*str == 'd')
		pf_putnbr(va_arg(args, int), count);
	else if (*str == '%')
		pf_putchar('%', count);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			pf_flags(args, (char *)(++str), &count);
			str++;
		}
		else
			pf_putchar(*(str++), &count);
	}
	va_end(args);
	return (count);
}
