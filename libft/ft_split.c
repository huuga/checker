/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlacresh <rlacresh@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:54:46 by rlacresh          #+#    #+#             */
/*   Updated: 2021/04/19 21:23:55 by rlacresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memcpy(void *dest, void *src, int n)
{
	char	*dest_copy;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_copy = dest;
	while (n)
	{
		*dest_copy = *(char *)src;
		dest_copy++;
		src++;
		n--;
	}
	*dest_copy = 0;
	return (dest);
}

//counting len of str, while char c is not appear
static int	strclen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

//counting number of words
static int	num_of_words(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			num++;
		}
		if (*s != 0)
			s++;
	}	
	return (num);
}

static void	split2(char const **s, char *c, char ***result, int *n_o_w)
{
	*s += strclen(*s, *c);
	(*result)++;
	(*n_o_w)--;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**result_c;
	int		n_o_w;

	if (s == NULL)
		return (NULL);
	n_o_w = num_of_words(s, c);
	result = (char **)malloc(sizeof(char *) * n_o_w + 1);
	result_c = result;
	if (result == NULL)
		return (NULL);
	while (*s && n_o_w > 0)
	{
		if (*s != c)
		{			
			*result = (char *)malloc(sizeof(char) * strclen(s, c) + 1);
			if (ft_memcpy((void *)*result, (void *)s, strclen(s, c)) == NULL)
				return (NULL);
			split2(&s, &c, &result, &n_o_w);
		}
		s++;
	}
	*result = NULL;
	return (result_c);
}
