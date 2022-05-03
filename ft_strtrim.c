/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:20:19 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/12 15:20:20 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	where_is_head(const char *src, const char *set)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (ft_strchr(set, src[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	where_is_tail(const char *src, const char *set)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	while (src_len > 0)
	{
		if (ft_strchr(set, src[src_len - 1]) == NULL)
			break ;
		src_len--;
	}
	return (src_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	head = where_is_head(s1, set);
	tail = where_is_tail (s1, set);
	if (head >= tail)
		return (ft_strdup(""));
	return (ft_substr(s1, head, tail - head));
}
