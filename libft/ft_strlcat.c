/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:12:33 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 21:27:56 by rlacresh         ###   ########.fr       */
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

size_t 	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	char	*dst_copy;
	char	*src_copy;
	size_t	n;
	size_t	dlen;

	dst_copy = (char *)dst;
	src_copy = (char *)src;
	n = dsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dst_copy;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - src_copy));
}
