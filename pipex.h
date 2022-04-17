/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orbiay <orbiay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:21:00 by orbiay            #+#    #+#             */
/*   Updated: 2022/03/03 11:45:01 by orbiay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		check_space(char *s);
int		ft_strlen_c(char *s, char c);
char	**split_cmd(char *s, char **str);
void	f_ok2(char *av, int i);
char	*r_cmd(char **c_arg, char **env);
void	check(int id);

#endif
