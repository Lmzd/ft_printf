/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:10:31 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 16:28:28 by pblouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define TYPES "sSpdDioOuUxXcC" /* paul : c'est quoi l'interet de ça ? doublon avec l'enum ? */

typedef struct s_data	t_data;

enum	e_length
{
	null, hh, h, l, ll, j, z
} 		length;

enum	e_types
{
	s, S, p, d, D, i, o, O, u, U, x, X, c, C
}		types;

typedef struct	s_flags
{
	int				zero;
	int				hashtag;
	int				plus;
	int				dash;
	int				spaces;
	enum e_length	length;
}				t_flags;

typedef struct	s_data
{
	char 	*text;					/* le texte avant le % recontré*/
	t_flags			flags;			/* le flag */
	char			*expression; 	/* l'expression entiere sans le % sign au debut */
	int				width;			/* la taille minimale de l'output */
	enum e_types	type;			/* le type du content */
	int				precision;		/* la precision exigée en int */
	void			*value;			/* la variable envoyé correspondant au type demandé recupéré depuis va_ap */
	void			*buffer;		/* la valeur final retourné */
	int				buffer_len;		/* la longeur du buffer a afficher */
	t_data			*next;			/* la prochaine structure */
}				t_data;

/*
** Parser Function
*/
t_data			*ft_parser(const char *format, va_list ap);
int				ft_get_regex_len(char **src);
char			*ft_find_regex(char **src);
void			ft_append(t_data **lst, t_data *new);
t_data			*ft_parser_option_checker(t_data *elem);
int				ft_parser_get_width_zero_opt(char *reg);
int				ft_parser_get_width(char *reg);

#endif