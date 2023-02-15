/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:35:34 by otaraki           #+#    #+#             */
/*   Updated: 2023/02/15 17:06:47 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int error(int E)
{
    if (E == 1)
    {
        perror("Error");
        exit (1); 
    }
    else if(E == 2)
    {
        perror("second cmd Invalid");
        exit (1);
    }
    else if (E == 3)
    {
        perror("second cmd Invalid");
        exit(1);
    }
    else if (E == 4)
    {
        write(2, "zsh: no such a file or directory\n", 34);
        exit(1);
    }
    return (0);
}
