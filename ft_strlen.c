/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:46:01 by orbiay            #+#    #+#             */
/*   Updated: 2022/02/28 11:00:55 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

char	**split_cmd(char *s, char **str)
{
	int	i;

	str[0] = ft_substr(s, 0, ft_strlen_c(s, ' '));
	str[1] = " ";
	return (str);
}

int	check_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] == 39 && s[i] == ' ' && s[i + 2] == ' ')
			return (1);
		i++;
	}
	return (0);
}
