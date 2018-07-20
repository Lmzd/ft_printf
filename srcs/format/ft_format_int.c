/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:34:30 by pblouin           #+#    #+#             */
/*   Updated: 2018/07/20 15:44:40 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** #name : ft_width_handler 
** #brief : 
** #notes :
** a externaliser comme service independant si possible
** c'est surement la meme maniere que de gerer
** la precision (au details pres de troncate VS round en plus)
*/
// void    ft_width_handler(t_data *data)
// {
//     int len;

//     len = ft_strlen(data->buffer);
//     if (data->width < 0)
//         /* precision par defaut : @louis : comment on gere çå ? */
//     // et maintenant 3 cas possible : < OR > OR == (@louis : peut on grouper == avec un des deux autres ?)
//     else if (data->width < len)
//         /* cut ? but how ? */
//     else (data->width > len)
//         /* add space or 0 based on which flag is up */
// }


/*
** #name : ft_format_int
** #brief : main recipe for formatting int (for type "d" and "i")
** 
*/
void	ft_format_int(t_data *data, va_list ap)
{
    char    *str;

    // /* 0. setup et error check */
    if (!data)
        return ;

    /* tmp : itoa for dev mode */
    str = ft_itoa(va_arg(ap, int));

    /*
    ** 1. d'abord modificateurs de type (h / hh / L / l ... =>
    ** quelle est la liste exact des flags utilisé ici ?)
    */
    // if -1
    //     continue ;
    // else if (data->flag)
    // else if hh
    // else if l
    // else ?

    /* 2. puis la precision (par défaut si rien n'est donné par l'user) */

    // if -1
    //     precision par defaut : 1
    // else

    // /* 3. convertir le nbr to str */
    // //dans une fonction helpers au dessus qui utilise itoa_base

    /* 4. puis la largeur */
    ft_width_handler(data);

    // /* 5. puis les options ( - / + / 0 / ' ' / #) */
    // //toujours a l'aide d'une library ?

    // /* 6. on commit le change dans le buffer de l'element de LL */
    data->buffer = str;
}

/*
%d

va_arg

long long int value
u_value ?

1. get arg (cast)
    if curr->flag == h
        value = (short)va_arg
    else if curr->flag == ll
        value = (long long int)va_arg



    if current->type == "d"
        long long int value = (long long int)va_arg

2. 4bits => 2bits => 
*/