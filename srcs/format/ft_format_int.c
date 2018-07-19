#include "../../includes/ft_printf.h"
#include "../../includes/ft_format.h"

void	ft_format_int(t_data *data)
{
    char    *str;

    /* 0. setup et error check */
    if (!data)
        exit ;

    /* 1. d'abord modificateurs de type (h / hh / L / l ...) */
    if -1
        continue ;
    else if (data->flag)
    else if hh
    else if l
    else ?

    /* 2. puis la precision (par défaut si rien n'est donné par l'user) */
    if -1
        precision par defaut : 1
    else

    /* 3. convertir le nbr to str */
    //dans une fonction helpers au dessus qui utilise itoa_base

    /* 4. puis la largeur */
    //a l'aide d'une library ?

    /* 5. puis les options ( - / + / 0 / ' ' / #) */
    //toujours a l'aide d'une library ?

    /* 6. on commit le change dans le buffer de l'element de LL */
    data->buffer = str;
    free (str); // ??cela risque t il de supprimer notre str fraichement assemblée et rangeee dans le buffer de la LL
}