/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:22:33 by orbiay            #+#    #+#             */
/*   Updated: 2022/02/17 10:48:43 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*ts1;
	unsigned char		*ts2;

	i = 0;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	while ((ts1[i] || ts2[i]) && i < n)
	{
		if (ts1[i] != ts2[i])
			return (ts1[i] - ts2[i]);
		i++;
	}
	return (0);
}
