/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:02:34 by hhashiba          #+#    #+#             */
/*   Updated: 2022/02/18 13:02:35 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dst, const char *src, size_t maxlen)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i] != '\0' && i < maxlen)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst);
}

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < maxlen)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (src_len);
	dst_len = ft_strnlen(dst, dstsize);
	if (dst_len == dstsize)
		return (src_len + dstsize);
	dst = ft_strncat(&dst[dst_len], src, dstsize - dst_len - 1);
	return (src_len + dst_len);

	// size_t	dst_len;

	// if (dst == NULL && dstsize == 0)
	// 	return (ft_strlen(src));
	// dst_len = ft_strnlen(dst, dstsize);
	// if (dst_len == dstsize)
	// 	return (ft_strlen(src) + dstsize);
	// return (ft_strlcpy(dst, src, dstsize));
}
