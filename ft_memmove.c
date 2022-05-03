/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:56:29 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/05 20:56:31 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)buf1;
	src = (const unsigned char *)buf2;
	if (!(n == 0 || dst == src))
	{
		i = 0;
		if (dst < src)
		{
			while (i < n)
			{
				dst[i] = src[i];
				i++;
			}
		}
		else
		{
			while (i++ < n)
				dst[n - i] = src[n - i];
		}
	}
	return (dst);
}
