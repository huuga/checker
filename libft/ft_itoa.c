/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:58:58 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/19 14:48:59 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	copier(int n, char *result)
{
	if (n > 0)
	{
		while (n > 0)
		{
			*result++ = (n % 10) + 48;
			n = n / 10;
		}
	}
	else if (n < 0)
	{
		while (n < 0)
		{
			*result++ = -(n % 10) + 48;
			n = n / 10;
		}
		*result++ = '-';
	}
	else
		*result++ = '0';
	*result = 0;
}

static	int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

static void	strrev(char *res)
{
	size_t	i;
	char	temp;
	size_t	res_len;

	i = 0;
	res_len = ft_strlen(res);
	while (i < res_len / 2)
	{
		temp = res[i];
		res[i] = res[res_len - i - 1];
		res[res_len - i - 1] = temp;
		i++;
	}
}

static unsigned int	size_of_int(int n)
{
	unsigned int	k;

	k = 0;
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			k++;
		}
		return (k);
	}
	else if (n < 0)
	{
		while (n < 0)
		{
			n = n / 10;
			k++;
		}
		return (k + 1);
	}
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	n_size;

	n_size = size_of_int(n);
	result = (char *)malloc(n_size * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	copier(n, result);
	strrev(result);
	return (result);
}
