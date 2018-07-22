
#include "../../includes/ft_printf.h"

void    ft_format_no_width_handler(t_data *elem, int width, int len)
{
    char	*str;

    if (elem->neg)
    {
            str = ft_strnew(len + 2);
            str[0] = '-';
            ft_strcat(str, elem->buffer);
            elem->buffer = ft_strdup(str);
            free(str);
    }
}

void    ft_format_width_handler_helper(t_data *elem, int width, int len, char extension)
{
    char	*str;
    int     index;
    int     neg;
    
    neg = elem->neg;
    str = ft_strnew(width + neg + 1);
	while(len--)
		str[--width] = elem->buffer[len];
	while(width--)
		str[width] = extension;
    if (neg)
    {
        if (elem->flags.zero)
            str[0] = '-';
        else {
            index = 0;
            while (str[index] < '0' || str[index] > '9')
                index++;
            elem->buffer = ft_strreplace(str, '-', --index);
            return ;
        }
    }
	elem->buffer = ft_strdup(str);
	free(str);
}

void	ft_format_width_handler(t_data *elem)
{
	int		len;
	int 	width;
	char	extension;

	len = ft_strlen(elem->buffer);
	width = elem->width;
    if (width <= len)
    {
        ft_format_no_width_handler(elem, width, len);
        return ;
    }
	extension = ' ';
	if (width > len)
    {
		if (elem->flags.zero)
			extension = '0';
    }
    else
		return ;
	ft_format_width_handler_helper(elem, width, len, extension);
}
