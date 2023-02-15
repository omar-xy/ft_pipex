/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:42:37 by otaraki           #+#    #+#             */
/*   Updated: 2023/02/15 17:00:40 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **env)
{
	int		i;
	char	**my_path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			my_path = ft_split(&env[i][5], ':');
			if (!my_path)
				return (NULL);
		}
		i++;
	}
	return (my_path);
}

char	*check_path(char **s_path, char *cmd)
{
	int		i;
	char	*j_cmd;
	char	*j_path;

	i = 0;
	if (access(cmd, X_OK) == 0) 
		return (cmd);
	j_cmd = ft_strjoin("/", cmd);
	if (!j_cmd)
		return (NULL);
	while (s_path[i])
	{
		j_path = ft_strjoin(s_path[i], j_cmd);
		if (access(j_path, X_OK) == 0)
		{
			free(j_cmd);
			return (j_path);
		}
		free(j_path);
		i++;
	}
	free(j_cmd);
	return (NULL);
}

