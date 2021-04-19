/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:22:37 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/18 10:57:51 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	copier(char **dst, const char **s, size_t *n)
{
	(*n)--;
	while (*n != 0)
	{									
		**dst = **s;
		if (**dst == '\0')
			break ;
		(*dst)++;
		(*s)++;
		(*n)--;
	}
	(*s)++;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)		
{
	const char	*s;
	size_t		n;

	n = size;
	s = src;
	if (src == NULL || dst == NULL)
		return (0);
	if (n != 0)
		copier(&dst, &s, &n);
	if (n == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*s)
			s++;
		s++;
	}
	return (s - src - 1);
}
