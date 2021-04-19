/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:46:00 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/19 18:58:28 by rlacresh         ###   ########.fr       */
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

static	int	compare_needle(const char *haystack, const char *needle,
							size_t needle_size, size_t *len)
{
	while ((*haystack || *needle) && needle_size && *len)
	{
		if (*haystack != *needle)
		{
			return (*haystack - *needle);
		}
		haystack++;
		needle++;
		needle_size--;
		(*len)--;
	}
	if (*needle == '\0')
		return (0);
	else
		return (-1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*needle_start;
	size_t	needle_size;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_start = (char *)needle;
	needle_size = ft_strlen(needle);
	while (*haystack && len)
	{
		if (*haystack == *needle)
			if (compare_needle(haystack, needle, needle_size, &len) == 0)
				return ((char *)haystack);
		haystack++;
		if (len)
			len--;
		needle = needle_start;
	}
	return (NULL);
}
