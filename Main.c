/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:22:49 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 07:06:17 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int     main(int ac, char **av, char **env)
{
    signal(SIGINT, sigintHandler);
    signal(SIGABRT, exitSignalHandler);
    char    *line_input;
    char    **command;
    pid_t   child_pid;
    int     stat_loc;
    pid_t   parent_pid;
    extern  char **environ;
    
    miniShellHeader();
    while (1)
    {
        prompt();
        parent_pid  = getpid();
        //If line not empty
        if(get_next_line(0, &line_input) >= 0)
        {
            child_pid = fork();
            if (child_pid == 0)
            {
                command = ft_strsplit(ft_strtrim(line_input), ' ');
                if (ft_strcmp(ft_ignoreCase(command[0]), "exit") == 0)
                    kill(child_pid, 6);
                chooseCommand2Exec(command, initGlobalEnvVar(env), environ);
            }
            else
                waitpid(child_pid, &stat_loc, WUNTRACED);
        }
    }
    return (0);
}