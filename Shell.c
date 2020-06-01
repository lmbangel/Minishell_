/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:13:06 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 18:13:53 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    miniShellHeader(void)
{
    ft_putstr("\033[31m--------------------\033[0m");
	ft_putstr("\033[31mMINISHELL---------------------\033[0m\n");
	ft_putstr("\033[32mWorking Commands\033[0m:\n");
	ft_putstr("\033[34m*echo\033[0m\n");
	ft_putstr("\033[34m*cd\033[0m\n");
	ft_putstr("\033[34m*env\033[0m\n");
	ft_putstr("\033[34m*setenv\033[0m\n");
	ft_putstr("\033[34m*unsetenv\033[0m\n");
	ft_putstr("\033[34m*exit\033[0m\n");
	ft_putstr("\033[31m----------------------------\033[0m");
	ft_putstr("\033[31m-----------------------\033[0m\n");
}

void    prompt(void)
{
    ft_putstr("\033[33mlmbangel@WTC_.local zsh>\033[0m ");
}

char    *ft_ignoreCase(char *string)
{
    int *string_out = (int *)malloc(sizeof(char *) * ft_strlen(string));
    char *string_out2 = (char *)malloc(sizeof(char *) * ft_strlen(string));
    int i = 0;
    int k = 0;
    while (string[i] != '\0')
    {
        string_out[i] = string[i];
        i++;
    }
    while (string_out[k])
    {
        string_out2[k] = ft_tolower(string_out[k]);
        k++;
    }
    string_out2[k] = '\0';
    return (string_out2);
}

char	**ft_strcat2(char **s1, char *s2)
{
	int	i;

	i = envv_len(s1);
	*(s1 + i) = s2;
	return (s1);
}

void    envVars(char **command, char **env)
{
    if (ft_strcmp(ft_ignoreCase(command[0]), "env") == 0)
        env_env(command, initGlobalEnvVar(env));
    else if (ft_strcmp(ft_ignoreCase(command[0]), "setenv") == 0)
        setenvVar(command, initGlobalEnvVar(env));
    else if (ft_strcmp(ft_ignoreCase(command[0]), "unsetenv") == 0)
        unsetEnvVariable(command[1], initGlobalEnvVar(env));
}

char    *check_bins(char **command)
{
	int				i;
	char			*bin_path;
	char			**path;
	struct stat		f;
    
    path = NULL;
    if (returnHomePath_("$PATH", g_env))
	    path = ft_strsplit(ft_strdup(returnHomePath_("$PATH", g_env)), ':');
	i = -1;
	while (path && path[++i])
	{
		if (ft_strstartswith(command[0], path[i]))
			bin_path = ft_strdup(command[0]);
		else
			bin_path = ft_strcat(ft_strcat(path[i], "/"), command[0]);
		if (lstat(bin_path, &f) == -1)
            free(bin_path);
		else
		{
		    free(path);
			return (bin_path);
		}
	}
	free(path);
	return (bin_path);
}


void    chooseCommand2Exec(char **command, char **env, char **enviro)
{
    if (ft_strcmp(ft_ignoreCase(command[0]), "echo") == 0)
        echoCommandFunction(command, initGlobalEnvVar(env));
    else if (ft_strcmp(ft_ignoreCase(command[0]), "cd") == 0)
        cdCommand(command, env);
    else if (ft_strcmp(ft_ignoreCase(command[0]), "env") == 0
    || ft_strcmp(ft_ignoreCase(command[0]), "setenv") == 0 ||
    ft_strcmp(ft_ignoreCase(command[0]), "unsetenv") == 0)
        envVars(command, initGlobalEnvVar(env));
    else
    {
        if(((execve(check_bins(command) , command,  initGlobalEnvVar(env))) == -1) ||
        ft_strcmp(check_bins(command), NULL) == 0)
        {
            if (ft_strcmp(ft_strndup(ft_ignoreCase(command[0]), 4), "/bin") == 0 ||
            ft_strcmp(ft_strndup(ft_ignoreCase(command[0]), 4), "/usr") == 0)
                execvp(command[0], command);
            else
            {
                ft_putstr("zsh: command not found: ");
                ft_putstr(ft_strcat(command[0], "\n"));  
            } 
        }
    }      
}