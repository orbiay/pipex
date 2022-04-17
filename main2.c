/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:41:06 by orbiay            #+#    #+#             */
/*   Updated: 2022/03/05 11:53:41 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	if_ok(char *av)
{
	if (access(av, X_OK) == 0)
		return (1);
	return (0);
}

void	execute_cmd1(char **av, char **env, int pipe_id[])
{
	int		fd;
	char	**c_arg;
	char	*cmd;

	f_ok2(av[1], 0);
	f_ok2(av[1], 1);
	c_arg = ft_split(av[2], ' ');
	if (if_ok(c_arg[0]))
		cmd = c_arg[0];
	else
	{
		c_arg[0] = ft_strjoin("/", c_arg[0]);
		cmd = r_cmd(c_arg, env);
	}
	fd = open(av[1], O_RDONLY);
	close(pipe_id[0]);
	dup2(fd, 0);
	dup2(pipe_id[1], 1);
	while(1);
	execve(cmd, c_arg, env);
}

void	execute_cmd2(char **av, char **env, int pipe_id[])
{
	int		fd;
	char	**c_arg;
	char	*cmd;

	c_arg = ft_split(av[3], ' ');
	if (if_ok(c_arg[0]))
		cmd = c_arg[0];
	else
	{
		c_arg[0] = ft_strjoin("/", c_arg[0]);
		cmd = r_cmd(c_arg, env);
	}
	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0600);
	f_ok2(av[4], 2);
	close(pipe_id[1]);
	dup2(pipe_id[0], 0);
	dup2(fd, 1);
	execve(cmd, c_arg, env);
}

int	main(int ac, char **av, char **env)
{
	int	id;
	int	pipe_id[2];

	if (ac != 5)
		return (1);
	pipe(pipe_id);
	id = fork();
	check(id);
	if (id == 0)
		execute_cmd1(av, env, pipe_id);
	id = fork();
	check(id);
	if (id == 0)
		execute_cmd2(av, env, pipe_id);
	close(pipe_id[0]);
	close(pipe_id[1]);
	while (wait(NULL) != -1)
	{
	}
}
