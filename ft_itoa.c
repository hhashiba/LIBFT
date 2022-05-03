/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:43:52 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/13 17:43:54 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static char	*itoa_changer(char *str, long int num, unsigned int digit)
{
	size_t			i;
	unsigned int	num_place;

	i = 0;
	if (num < 0)
	{
		str[i] = '-';
		num *= -1;
		i++;
	}
	num_place = ft_recursive_power(10, digit - i - 1);
	while (i < digit)
	{
		str[i] = num / num_place + '0';
		num %= num_place;
		num_place /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
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

char	*ft_itoa(int n)
{
	size_t	digit;
	char	*str;

	digit = how_many_digit((long int)n);
	str = malloc((digit + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (itoa_changer(str, (long int)n, digit));
}
