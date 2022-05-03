/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:17:26 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/10 11:17:27 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	ch;

	i = 0;
	ch = c;
	len = ft_strlen(s);
	if (ch == '\0')
		return ((char *)s + len);
	while (i++ < len)
	{
		if (s[len - i] == ch)
			break ;
	}
	if (len + 1 != i)
		return ((char *)s + (len - i));
	return (NULL);
}
