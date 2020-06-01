/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:14:02 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 18:31:24 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    echoCommandFunction(char **command, char **env)
{
    int i;

    i = 0;
    while (command[++i])
    {
        if (command[i][0] == '$')
            echoEnvironmentVariable(command[i], env);
        else
            quotesAndEscape(command[i]);
    }
    ft_putchar('\n');
}

void    quotesAndEscape(char *string)
{
    int i;
    
    i = -1;
    while (string[++i])
    {
        if (string[i] == '"' || string[i] == '\\')
        {
            if (string[i] == '\\' && string[0] == '"' && string[(ft_strlen(string) - 1)] == '"')
            {
                if (string[i + 1] ==  'n' || string[i + 1] ==  't' || string[i + 1] ==  'v')
                {
                    newlineAndTabs(string[i + 1]);
                    i++;
                }
            }
        }
        else
            ft_putchar(string[i]);
    }
}

void    newlineAndTabs(char c)
{
    if (c == 'n' || c == 'v')
        ft_putchar('\n');
    else
        ft_putchar('\t');
}

void    echoEnvironmentVariable(char *command, char **environ)
{
    int i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(ft_ignoreCase(environ[i]), ft_ignoreCase(command + 1), ft_strlen(command) - 1) == 0)
		{
			ft_putstr((environ[i] + ft_strlen(command)));
			break ;
		}
		i++;
	}
}