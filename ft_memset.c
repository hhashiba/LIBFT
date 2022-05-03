/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:59:17 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/05 16:59:19 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*mem;
	unsigned char	set;

	i = 0;
	mem = (unsigned char *)buf;
	set = (unsigned char)ch;
	while (i < n)
	{
		mem[i] = set;
		i++;
	}
	return (mem);
}
