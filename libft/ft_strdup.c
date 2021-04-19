/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:03:52 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 20:35:11 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	ft_strlen(const char *str)
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

char	*ft_strdup(const char *src)
{
	char	*result;
	char	*result_copy;

	result = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (result == NULL)
		return (NULL);
	result_copy = result;
	while (*src)
	{
		*result = *src;
		result++;
		src++;
	}
	*result = 0;
	return (result_copy);
}
