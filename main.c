/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:25:43 by orbiay            #+#    #+#             */
/*   Updated: 2022/04/02 10:16:38 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	check(int id)
{
	if (id == -1)
	{
		perror("");
		exit (1);
	}
}

char	*path(char **env)
{
	char	*save;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			save = env[i];
		i++;
	}
	save = ft_substr(save, 5, ft_strlen(save) - 5);
	return (save);
}

char	**split_path(char *save)
{
	char	**split_path;

	split_path = ft_split(save, ':');
	return (split_path);
}

void	f_ok2(char *av, int i)
{
	if (i == 0)
	{
		if (access(av, F_OK) == -1)
		{
			printf("zsh: permission denied: %s\n", av);
			exit(1);
		}
	}
	if (i == 1)
	{
		if (access(av, W_OK) == -1)
		{
			printf("zsh: permission denied: %s\n", av);
			exit(1);
		}
	}
	if (i == 2)
	{
		if (access(av, R_OK) == -1)
		{
			printf("zsh: permission denied: %s\n", av);
			exit(1);
		}
	}
}

char	*r_cmd(char **c_arg, char **env)
{
	char	*save;
	char	**s_path;
	char	*cmd;
	int		i;

	i = 0;
	save = path(env);
	s_path = split_path(save);
	while (s_path[i])
	{
		cmd = ft_strjoin(s_path[i], c_arg[0]);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		i++;
	}
	perror(NULL);
	printf("zsh: command not found: %s\n", c_arg[0]);
	exit(1);
}
