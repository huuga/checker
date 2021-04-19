/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:47:15 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 20:39:54 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	size_t	ssize;

	ch = c;
	ssize = ft_strlen(str);
	str = str + ssize;
	while (ssize > 0)
	{
		if (*str == ch)
			return ((char *)str);
		ssize--;
		str--;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}
