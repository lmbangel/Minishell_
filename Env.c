/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:26:12 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 06:20:04 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

char	**initGlobalEnvVar(char **env)
{
	int	i;
	
	i = -1;

	if (!g_env)
	{
		g_env = NULL;
		g_env = (char **)malloc(sizeof(char *) * envv_len(env) + 1);
		while (env[++i])
			g_env[i] = ft_strdup(env[i]);
		g_env[i] = NULL;
	}
	return (g_env);
}


int		envv_len(char **envv)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

void	print_env(char **envv)
{
	int i;

	i = 0;
	while (envv[i])
	{
		ft_putstr(envv[i]);
        if (envv[i + 1])
            ft_putchar('\n');
        i++;
	}
	ft_putchar('\n');
}

void    env_env(char **command, char **envv)
{
	if (!command[1])
		print_env(initGlobalEnvVar(envv));
	else if (command[1][0] == '$')
	{
		ft_putstr("env: ");
		echoEnvironmentVariable(command[1], initGlobalEnvVar(envv));
		ft_putstr(": Permission denied\n");
	}
	else
	{
        ft_putstr("env: ");
        ft_putstr(command[0]);
        ft_putstr(": No such file or directory");
    }
}