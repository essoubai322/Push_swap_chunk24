/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:13:50 by asebaai           #+#    #+#             */
/*   Updated: 2024/03/18 07:06:50 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler(int num)
{
    write(STDOUT_FILENO , "i won't die\n" , 12);
}
int main()
{
    signal(SIGINT , handler);
    signal(SIGTERM , handler);
    while(1)
    {
        printf("wasting your cycles %d\n" , getpid());
    }
}