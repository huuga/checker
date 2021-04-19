/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:09:09 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 20:31:59 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

//copy byte string
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*start_s;
	char		*start_d;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		start_s = (const char *)src;
		start_d = (char *)dest;
		while (len--)
			*start_d++ = *start_s++;
	}
	else
	{
		start_s = (const char *)src + (len - 1);
		start_d = (char *)dest + (len - 1);
		while (len--)
			*start_d-- = *start_s--;
	}
	return (dest);
}
