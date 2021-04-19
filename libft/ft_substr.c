/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 08:08:59 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/18 13:05:55 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

static void	*ft_memset(void *des, int c, size_t n)
{
	unsigned char	*str;

	str = des;
	while (n--)
		*str++ = c;
	return (des);
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = (void *)malloc(count * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, size * count);
	return (result);
}

//Allocates and returns a substring from the string ’s’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*result_copy;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	result_copy = result;
	if (s_len > start)
	{
		s = s + start;
		while (len > 0)
		{
			*result = *s;
			result++;
			s++;
			len--;
		}
	}
	return (result_copy);
}
