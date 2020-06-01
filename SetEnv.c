/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetEnv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 23:17:36 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 19:14:24 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	setenvVar(char **command, char **envv)
{
	int i;
    int x;

    i = -1;
    x = 0;
	if (command[2])
        ft_putstr("setenv: incorrect syntax [try: Variable=Value]\n");
    else if (command[1] && !command[2])
    {
        while (command[1][++i])
        {
            if (command[1][i] == '=')
            {
                x++;
                break;
            }
        }
        if (x == 1)
            adds_new_env_line(initGlobalEnvVar(envv), command[1]);
        else
            ft_putstr("setenv: incorrect syntax [try: Variable=Value]\n");
    }
    else if (!command[1] && !command[2])
        print_env(initGlobalEnvVar(envv));
}

void    resetGlobalVar(char **env)
{
	int	i;
	
	i = 0;
    g_env = NULL;
	g_env = (char **)malloc(sizeof(char *) * envv_len(env) + 1);
	while (env[i])
	{
		g_env[i] = ft_strdup(env[i]);
		++i;
	}
	g_env[i] = NULL;
}


char	**adds_new_env_line(char **env, char *new_line)
{
	char **new;
	int i;

    new = NULL;
	new = (char **)malloc(sizeof(char *) * ((envv_len(g_env)) + 2));
	i = 0;
	while (g_env[i])
	{
		new[i] = ft_strdup(g_env[i]);
        free(g_env[i]);
		i++;
	}
	new[i] = new_line;
    resetGlobalVar(new);
    free(new);
	return (NULL);
}
