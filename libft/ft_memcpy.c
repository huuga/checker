/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:08:56 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 20:29:46 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_copy;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_copy = dest;
	while (n--)
		*dest_copy++ = *(char *)src++;
	return (dest);
}
