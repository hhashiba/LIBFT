/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:10:34 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/08 21:10:36 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	int					diff;
	const unsigned char	*s_1;
	const unsigned char	*s_2;

	i = 0;
	diff = 0;
	s_1 = (const unsigned char *)s1;
	s_2 = (const unsigned char *)s2;
	while (i < n)
	{
		diff = s_1[i] - s_2[i];
		if (diff != 0)
			break ;
		i++;
	}
	return (diff);
}
