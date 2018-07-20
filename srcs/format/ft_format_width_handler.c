void	ft_format_width_handler(t_data *data)
{
	int		len;
	char	extension;
	char	*str;

	extension = ' '
	
	len = ft_strlen(data->buffer);
	if (data->width > len)
	{
		if (data->flags->zero)
			extension = '0';
	}
	str = ft_strnew(width + 1)
	while(len--)
		str[--width] = data->buffer[len];
	while(width--)
		str[width] = extension;
}
