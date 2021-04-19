/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:35:12 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/18 16:58:31 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

//locate character in string
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == 0 && *str == 0)
		return ((char *)str);
	return (NULL);
}
