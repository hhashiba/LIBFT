/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:20:24 by hhashiba          #+#    #+#             */
/*   Updated: 2022/02/18 21:20:26 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static int	how_many_digit(long int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static int	ft_ltoi(int sign, size_t digit, const char *str)
{
	size_t		num;
	size_t		max;

	if (sign == -1)
		max = -LONG_MIN;
	else
		max = LONG_MAX;
	if (digit > (size_t)how_many_digit(LONG_MAX))
		return ((int)max * sign);
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (num > max)
		return ((int)max * sign);
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	digit;

	sign = 1;
	digit = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(str[digit]))
		digit++;
	return (ft_ltoi(sign, digit, str));
}
