#ifndef FT_FORMAT_H
# define FT_FORMAT_H

void    ft_format_data_with_type(t_data *data);

# define TYPE_INT	'd'


typedef struct	s_fmt_type
{
	char	type;
	char	*(*f)(int);
}				t_fmt_type;

t_fmt_type	g_types[] =
{
	{TYPE_INT, &ft_itoa},
	{0, NULL}
};

#endif