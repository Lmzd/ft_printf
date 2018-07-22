#include "../../../includes/ft_printf.h"

void    ft_format_hex_modifier(t_data *elem, va_list ap)
{
    intmax_t value;
    t_modifier modifier;

    modifier = elem->modifier;
    if (modifier.hh)
    {
        modifier.h = 0;
        value = (char)va_arg(ap, int);
    } else if (modifier.h)
        value = (short)va_arg(ap, int);
    else if (modifier.l)
        value = va_arg(ap, long int);
    else if (modifier.ll)
        value = va_arg(ap, long long int);
    else if (modifier.j)
        value = va_arg(ap, intmax_t);
    else if (modifier.z)
        value = va_arg(ap, size_t);
    else
        value = va_arg(ap, int);
    elem->neg = (value >= 0) ? 0 : 1;
    elem->buffer = ft_itoa_base_intmax(ft_abs_intmax(value), 16);
    elem->buffer_len = ft_strlen(elem->buffer);
}

static void     ft_format_case_modifier(t_data *data)
{
    if data->type = 'X'
        data->buffer = ft_toupper(data->buffer);
}

static void     ft_format_hex_prefix(t_data *data)
{
    if (data->hash)
        data->buffer = ft_strcat(HEX_PREFIX, data->buffer);
}

void	ft_format_hex(t_data *elem, va_list ap)
{
    char *value;

    ft_format_hex_modifier(elem, ap);
    ft_format_hex_prefix(elem);
    ft_format_case_modifier(elem);
	
	/* comportement a tester et adapter */
    if (!elem->flags.dash \
       || (elem->flags.dash && (elem->width < elem->buffer_len)))
    {
        ft_format_width_handler(elem);
        ft_format_plus_flag_handler(elem);
        ft_format_space_flag_handler(elem);
    } else {
        ft_format_moins_flag_handler(elem);
        ft_format_moins_flag_space_or_plus_handler(elem);
    }
}