/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaladri <sgaladri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:38:01 by sgaladri          #+#    #+#             */
/*   Updated: 2021/11/24 02:39:38 by sgaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
    
	for (i = 0; i < argc; i++)
    {
		printf("Argument %d: %s\n", i, argv[i]);
	}
}