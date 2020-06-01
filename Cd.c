/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 07:19:27 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 04:24:51 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

char    *returnHomePath_(char *command, char **environ)
{
    int i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(ft_ignoreCase(environ[i]), ft_ignoreCase(command + 1), ft_strlen(command) - 1) == 0)
		{
			return((environ[i] + ft_strlen(command)));
			break ;
		}
		i++;
	}
    return (NULL);
}

void    cdCommand(char **command, char **envv)
{
    char *path;
    if (!command[1] || (ft_strcmp(command[1], "~") == 0))
    {
        path = ft_strdup(returnHomePath_("$HOME", envv));
    }
    else
    {
        if (ft_strcmp(ft_ignoreCase(ft_strndup(command[1], 1)), "~") == 0)
        {
            path = ft_strcat(ft_strdup(returnHomePath_("$HOME", envv)), command[1] + 1);
        }
        else if(ft_strcmp(command[1], "-") == 0)
        {
            path = ft_strdup(returnHomePath_("$OLDPWD", envv));
        }
        else 
            path = command[1];
    }
    chdir(path);
}