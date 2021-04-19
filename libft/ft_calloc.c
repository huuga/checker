/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 07:17:13 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/17 20:17:09 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *des, int c, size_t n)
{
	unsigned char	*str;

	str = des;
	while (n--)
		*str++ = c;
	return (des);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = (void *)malloc(count * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, size * count);
	return (result);
}
