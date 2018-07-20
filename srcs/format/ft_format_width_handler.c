
#include "../../includes/ft_printf.h"

void	ft_format_width_handler(t_data *data)
{
	int		len;
	int 	width;
	char	extension;
	char	*str;

	extension = ' ';
	width = data->width;
	len = ft_strlen(data->buffer);
	if (width > len)
	{
		if (data->flags.zero)
			extension = '0';
	}
	str = ft_strnew(width + 1);
	while(len--)
		str[--width] = data->buffer[len];
	while(width--)
		str[width] = extension;
}
