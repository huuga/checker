/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:28:47 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/19 15:11:15 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

static char	*ft_strndup(const char *src, size_t n)
{
	char	*result;
	char	*result_copy;

	result = (char *)malloc(sizeof(char) * n + 1);
	if (result == NULL)
		return (NULL);
	result_copy = result;
	while (n)
	{
		*result = *src;
		result++;
		src++;
		n--;
	}
	*result = 0;
	return (result_copy);
}

static int	is_ch_in_str(const char *set, int c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*left;
	char	*right;
	size_t	diff;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	left = (char *)s1;
	right = (char *)s1 + s1_len - 1;
	while (is_ch_in_str(set, *left))
		left++;
	if (*left != '\0')
	{
		while (is_ch_in_str(set, *right) && s1_len > 1)
		{
			right--;
			s1_len--;
		}
		diff = right - left + 1;
		return (ft_strndup(left, diff));
	}
	return (ft_strndup(left, ft_strlen(left)));
}
