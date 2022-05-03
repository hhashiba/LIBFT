/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhashiba <hhashiba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:35:22 by hhashiba          #+#    #+#             */
/*   Updated: 2022/04/12 08:35:23 by hhashiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_many_arrays(const char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
			cnt++;
		while (*str != '\0' && *str != c)
			str++;
	}
	return (cnt);
}

static char	*store_in_arrays(const char *src, char c)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**dealloc_arrays(char **arrays)
{
	while (*arrays != NULL)
	{
		free(*arrays);
		arrays++;
	}
	return (arrays);
}

static char	**split_main(char **strs, char const *src, char c)
{
	size_t	i;

	i = 0;
	while (*src != '\0')
	{
		while (*src != '\0' && *src == c)
			src++;
		if (*src != '\0')
		{
			strs[i] = store_in_arrays(src, c);
			if (strs[i] == NULL)
				return (dealloc_arrays(strs));
			i++;
		}
		while (*src != '\0' && *src != c)
			src++;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char const *src, char c)
{
	size_t	cnt;
	char	**strs;

	if (src == NULL)
		return (NULL);
	if (src[0] == '\0' && c == '\0')
		return (ft_calloc(1, sizeof(char *)));
	cnt = how_many_arrays(src, c);
	if (cnt == 0)
		return (ft_calloc(1, sizeof(char *)));
	strs = malloc((cnt + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	return (split_main(strs, src, c));
}
