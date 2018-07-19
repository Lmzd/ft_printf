/*
** @name:  ft_format_route()
** @brief:
** - prendre une element de la LL
** - et le route vers la bonne fonction de formattage (en fonction de son type)
** @return : nothing (buffered string is put in )
*/

#include "../../includes/ft_printf.h"
#include "../../includes/ft_format.h"

void    ft_format_router(t_data *data, va_list ap)
{
    int i;

    i = 0;
    while (g_types[i].type)
    {
        if (data->type == g_types[i].type)
            g_types[i].f(data, ap);
        i++;
    }
}
