/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:36:10 by tmuzeren          #+#    #+#             */
/*   Updated: 2019/06/06 12:05:25 by tmuzeren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fr_read(char const *s, int n)
{
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n++;
	return (n);
}

static int	back_read(char const *s, int n)
{
	while (s[n] == ' ' || s[n] == '\t' || s[n] == '\n')
		n--;
	return (n);
}

char		*ft_strtrim(char const *s)
{
	char			*fresh;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = fr_read(s, 0);
	if (s[i] == '\0')
		return ((char *)s + i);
	len = back_read(s, len);
	fresh = (char *)malloc(sizeof(char) * (len - i + 2));
	if (fresh != NULL)
	{
		while (s[i + j] != '\0' && j < len - i + 1)
		{
			fresh[j] = s[i + j];
			j++;
		}
		fresh[j] = '\0';
		return (fresh);
	}
	return (NULL);
}
