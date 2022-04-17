/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:19:50 by orbiay            #+#    #+#             */
/*   Updated: 2022/02/28 15:57:41 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

static int	counter_word(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static int	counter_alpha(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*convert(char const *s, int j)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	str = malloc((counter_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	if (check_space(s))
	{
		str = split_cmd(s, str);
		return (str);
	}
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
			str[k++] = convert(s + i, counter_alpha(s + i, c));
		while (s[i] && s[i] != c)
			i++;
	}
	str[k] = 0;
	return (str);
}
