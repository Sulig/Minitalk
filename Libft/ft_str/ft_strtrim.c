/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:16:49 by sadoming          #+#    #+#             */
/*   Updated: 2023/11/07 19:14:42 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cmp(const char *s, int c)
{
	int		pos;

	pos = 0;
	while (s[pos])
	{
		if ((unsigned char) s[pos] == (unsigned char) c)
			return (0);
		pos++;
	}
	return (1);
}

static char	*ft_dup(char *str, size_t len)
{
	char	*dup;
	size_t	ln;

	ln = 0;
	while (str[ln] && ln < len)
		ln++;
	dup = malloc(ln + 1);
	if (dup == 0)
		return (0);
	ln = 0;
	while (str[ln] && ln < len)
	{
		dup[ln] = str[ln];
		ln++;
	}
	dup[ln] = '\0';
	return (dup);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	ln;
	size_t	cnt;

	if (s1[0] == '\0')
		return (ft_dup("", 0));
	if (set[0] == '\0')
		return (ft_dup((char *)s1, 1000));
	ln = 0;
	while (s1[ln])
	{
		if (ft_cmp(set, s1[ln]) == 1)
			break ;
		ln++;
	}
	cnt = 0;
	while (s1[cnt + 1])
		cnt++;
	while (cnt >= 0)
	{
		if (ft_cmp(set, s1[cnt]) == 1)
			break ;
		cnt--;
	}
	return (ft_dup((char *) s1 + ln, (cnt + 1) - ln));
}
