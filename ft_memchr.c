/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:07:17 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/08 22:07:18 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*mem;
	unsigned char		set;

	i = 0;
	mem = (const unsigned char *)s;
	set = (unsigned char)c;
	while (i < n)
	{
		if (mem[i] == set)
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}
