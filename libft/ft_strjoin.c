/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 08:23:52 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 20:36:18 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*dest_copy;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_copy = dest;
	while (n--)
		*dest_copy++ = *(char *)src++;
	return (dest);
}

static size_t	ft_strlen(char *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	ft_memcpy((void *)result, (void *)s1, s1_len);
	ft_memcpy((void *)(result + s1_len), (void *)s2, s2_len + 1);
	return (result);
}
