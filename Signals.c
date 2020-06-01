/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmbangel <lmbangel@student.wethinkcode.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:58:48 by lmbangel          #+#    #+#             */
/*   Updated: 2020/05/30 19:07:22 by lmbangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void    sigintHandler(int signalNumber)
{
    ft_putchar('\n');
    prompt();
}
void    exitSignalHandler(int signalNumber)
{
    ft_freestrarr(g_env);
    exit(0);
}