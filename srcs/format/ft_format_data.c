/*
** @name:  ft_format_data()
** @brief:
** - prendre une element de la LL
** - traite la value en fonction des options de format
** - et renvoie la chaine de char bufferised dans la data structure (pointer : content)
*/

#include "../../includes/ft_printf.h"
#include "../../includes/ft_format.h"

void    ft_format_data_with_type(t_data *data)
{
    while (s_fct)
    {
        if s_data->type = format_fct_pool->type
        {
            s_data->bufferised = format_fct_pool->f(s_data->value);
            exit ;
        }
        s_fct = s_fct->next;
    }
    if (data->type == g_types[0].type)
        data->buffer = g_types[0].f((int)42);
}
