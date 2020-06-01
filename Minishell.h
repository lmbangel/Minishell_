/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:25:43 by lmbangel          #+#    #+#             */
/*   Updated: 2020/06/01 12:34:45 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <string.h>

typedef void (*sighandler_t)(int);
/*
**  Shell.c [Non-Command Functions]
*/
void    miniShellHeader(void);
void    chooseCommand2Exec(char **command, char **env, char **enviro);
char    *ft_ignoreCase(char *string);
char	*check_bins(char **command);
char	**ft_strcat2(char **s1, char *s2);
void    envVars(char **command, char **env);
void    prompt(void);
/*
**  Echo.c
*/
void    echoCommandFunction(char **command, char **env);
void    quotesAndEscape(char *string);
void    newlineAndTabs(char c);
void    echoEnvironmentVariable(char *command, char **environ);
/*
**  Cd.c
*/
char    *returnHomePath_(char *command, char **environ);
void    cdCommand(char **command, char **envv);
/*
**  Signals.c
*/
void    sigintHandler(int signalNumber);
void    exitSignalHandler(int signalNumber);
/*
**  Env.c
*/
char	**initGlobalEnvVar(char **env);
int		envv_len(char **envv);
char    **g_env;
void	print_env(char **envv);
void    env_env(char **command, char **envv);
/*
**  SetEnv.c
*/
void	setenvVar(char **command, char **env);
void    resetGlobalVar(char **env);
char	**adds_new_env_line(char **env, char *new_line);
/*
**  Unsetenv.c
*/
void    deleteVar(int i);
void    unsetEnvVariable(char *command, char **envv);
#endif