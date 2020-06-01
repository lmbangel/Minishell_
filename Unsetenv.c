/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 01:38:41 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 07:07:13 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    deleteVar(int i)
{
    int y;
    
    g_env[i] = NULL;
	y = i;
	while (g_env[y + 1])
	{
		g_env[y] = ft_strdup(g_env[y + 1]);
		g_env[y + 1] = NULL;
		y++;
	}
}

void    unsetEnvVariable(char *command, char **envv)
{
    int i;
    int x;

	i = 0;
    x = 0;
    if (command != NULL)
    {
        while (envv[i])
        {
            if (ft_strncmp(ft_ignoreCase(envv[i]), ft_ignoreCase(command), ft_strlen(command) - 1) == 0)
            {
                x++;
                deleteVar(i);
                break ;
            }
            i++;
        }
        if (x == 0)
            ft_putstr("unsetenv: no such variable on the environment\n");
    }
    else
        ft_putstr("unsetenv: not enough arguments\n");
}