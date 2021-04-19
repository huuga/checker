/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:08:25 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 18:33:49 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

//copy string until character found
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{	
	char		f;

	f = c;
	while (n > 0)
	{
		*(char *)dest = *(char *)src;
		if (*(char *)dest == f)
		{
			return (dest + 1);
		}
		dest++;
		src++;
		n--;
	}	
	return (NULL);
}
