/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 09:52:05 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/10 09:52:07 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (ft_strchr(&haystack[i], needle[0]) && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
