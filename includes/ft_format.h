#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include "ft_formatters.h"

void	ft_format_router(t_data *data, va_list ap);

# define TYPE_INT	'd'


typedef struct	s_fmt_type
{
	char	type;
	void	(*f)(t_data *, va_list);
}				t_fmt_type;

t_fmt_type	g_types[] =
{
	{TYPE_INT,		&ft_format_int},
	{0, NULL}
};

//{TYPE_LONG,		&ft_format_long},
//{TYPE_STRING,	&ft_format_str},

#endif
