/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:42:55 by otaraki           #+#    #+#             */
/*   Updated: 2023/02/15 16:24:54 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int fd[], char **fe_cmd, char **se_cmd, char **env)
{
	int	status;
	int	id;

	id = fork();
	if (id == -1)
		return (error(1));
	if (id == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		if (execve(check_path(split_path(env), fe_cmd[0]), fe_cmd, env) == -1)
			return (error(1));
	}
	else if (fork() == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		if (execve(check_path(split_path(env), se_cmd[0]), se_cmd, env) == -1)
			return (error(1));
	}
	wait(&status);
	return (0);
}

int	main(int argc, char **av, char **envp)
{
	char	**f_cmd;
	char	**s_cmd;
	int		fd[2];
	int		infile;
	int		outfile;

	if (argc == 5)
	{
		f_cmd = ft_split(av[2], ' ');
		s_cmd = ft_split(av[3], ' ');
		if (((f_cmd[0][0] == '/') || (s_cmd[0][0] == '/'))
			&& ((access(f_cmd[0], F_OK) != 0) && (access(s_cmd[0], F_OK) != 0)))
			return (error(2));
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (dup2(infile, STDIN_FILENO) == -1
			|| dup2(outfile, STDOUT_FILENO) == -1
			|| pipe(fd) != 0)
			return (error(1));
		pipex(fd, f_cmd, s_cmd, envp);
		return (0);
	}
	write(2, "Error: Missing Args", 20);
	return (1);
}
