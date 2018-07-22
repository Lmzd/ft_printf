#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include "ft_formatters.h"

# define TYPE_INT_1	'd'
# define TYPE_INT_2 'D'
# define TYPE_INT_3 'i'
# define TYPE_HEX_1	'x'
# define TYPE_HEX_2	'X'

# define HEX_PREFIX  "0x"


typedef struct	s_fmt_type
{
	char	type;
	void	(*f)(t_data *, va_list);
}				t_fmt_type;

t_fmt_type	g_types[] =
{
	{TYPE_INT_1,		&ft_format_int},
	{TYPE_INT_2,		&ft_format_int},
	{TYPE_INT_3,		&ft_format_int},
	{TYPE_HEX_1,		&ft_format_hex},
	{TYPE_HEX_2,		&ft_format_hex},
	{0, 0}
};

//{TYPE_LONG,		&ft_format_long},
//{TYPE_STRING,	&ft_format_str},

#endif
