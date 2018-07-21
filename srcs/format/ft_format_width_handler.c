
#include "../../includes/ft_printf.h"

void    ft_format_no_width_handler(t_data *data, int width, int len)
{
    char	*str;

    if (data->neg)
    {
            str = ft_strnew(len + 2);
            str[0] = '-';
            ft_strcat(str, data->buffer);
            data->buffer = ft_strdup(str);
            free(str);
    }
}

void    ft_format_width_handler_helper(t_data *data, int width, int len, char extension)
{
    char	*str;
    int     index;
    int     neg;
    
    neg = data->neg;
    str = ft_strnew(width + neg + 1);
	while(len--)
		str[--width] = data->buffer[len];
	while(width--)
		str[width] = extension;
    if (neg)
    {
        if (data->flags.zero)
            str[0] = '-';
        else {
            index = 0;
            while (str[index] < '0' || str[index] > '9')
                index++;
            data->buffer = ft_strreplace(str, '-', --index);
            return ;
        }
    }
	data->buffer = ft_strdup(str);
	free(str);
}

void	ft_format_width_handler(t_data *data)
{
	int		len;
	int 	width;
	char	extension;

	len = ft_strlen(data->buffer);
	width = data->width;
    if (width <= len)
    {
        ft_format_no_width_handler(data, width, len);
        return ;
    }
	extension = ' ';
	if (width > len)
    {
		if (data->flags.zero)
			extension = '0';
    }
    else
		return ;
	ft_format_width_handler_helper(data, width, len, extension);
}
