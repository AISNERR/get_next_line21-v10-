/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaladri <sgaladri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:44:13 by sgaladri          #+#    #+#             */
/*   Updated: 2021/11/24 03:03:32 by sgaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rez=0;

//	opterr=0;
	while ((rez = getopt(argc, argv, "ab:C::d")) != -1)
    {
		switch (rez){
		case 'a': printf("found argument \"a\".\n"); break;
		case 'b': printf("found argument \"b = %s\".\n",optarg); break;
		case 'C': printf("found argument \"C = %s\".\n",optarg); break;
		case 'd': printf("found argument \"d\"\n"); break;
		case '?': printf("Error found !\n");break;
        }
	}
}