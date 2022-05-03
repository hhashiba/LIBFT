/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:48:28 by hhashiba          #+#    #+#             */
/*   Updated: 2022/02/17 21:48:29 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	int					diff;
	const unsigned char	*s_1;
	const unsigned char	*s_2;

	i = 0;
	diff = 0;
	s_1 = (const unsigned char *)s1;
	s_2 = (const unsigned char *)s2;
	if (!(s_1 == NULL && n == 0))
	{
		while ((s_1[i] != '\0' || s_2[i] != '\0') && i < n)
		{
			diff = s_1[i] - s_2[i];
			if (diff != 0)
				break ;
			i++;
		}
	}
	return (diff);
}
