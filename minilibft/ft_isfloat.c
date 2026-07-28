/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvitorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:05:17 by lvitorin          #+#    #+#             */
/*   Updated: 2026/07/27 19:05:20 by lvitorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char    ft_isfloat(char *string)
{
    int i; 
    int num;
    
    i = 0;
    num = 0;
    if (ft_isdigit(string[0]))
    {
        while (ft_isdigit(string[i]))
        {
            num = num * 10 + (string[i] - '0');
            i++;
        }
        if (string[i] != '.')
            return (string[i]);
        i++;
        while (ft_isdigit(string[i]))
	    {
	        num = num * 10 + (string[i] - '0');
	        i++;
	    }
	    return (string[i]);
	}
	return (string[0]);
}
