/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:32:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/02/14 18:54:14 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

// parsing_utils
char	**split_path(char **env);
int		error(int E);
char	*check_path(char **s_path, char *cmd);
int		pipex(int fd[], char **fe_cmd, char **se_cmd, char **env);

#endif
