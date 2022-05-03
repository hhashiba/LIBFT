/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:15:50 by hhashiba          #+#    #+#             */
/*   Updated: 2022/05/01 20:15:53 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)buf1;
	src = (const unsigned char *)buf2;
	if (!(n == 0 || dst == src))
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
