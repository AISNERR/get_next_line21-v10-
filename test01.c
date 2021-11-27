/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaladri <sgaladri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:17:53 by sgaladri          #+#    #+#             */
/*   Updated: 2021/11/24 04:34:33 by sgaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void redirect_stdout(char *);

void    redirect_stdout(char *filename) // HAVE TAKEN THE ARGUMENTS AND WILL PUT IT INTO THE FILE FOO   
{
    int fd;

    fd = open(filename, O_CREAT|O_WRONLY,0666);  // create the file named foo
    if (fd < 0)                                
    {
        perror(filename);
        exit(1);
    }
    close(1);                        
                                         
    if (dup(fd) !=1)                 
    {
        fprintf(stderr,"Unexpected dup failure\n");
        exit(1);
    }
    close(fd);                        
}
 
int main()
{
    printf("Hello world\n");
    //printf("Hello to you too, foo\n");       
                                       
    fflush(stdout);
    redirect_stdout("foo");         
    printf("Hello to you too, smth\n");
                                       
    fflush(stdout);
}

 