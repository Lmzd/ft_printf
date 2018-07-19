/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:32:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/19 16:58:30 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct	s_flags
{
	int			zero;
	int			hashtag;
	int			plus;
	int			dash;
	int			spaces;
	int			length;
}				t_flags;

typedef struct	s_modifier
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_modifier;

typedef struct      s_data  t_data;
typedef struct		s_data
{
    char 			*text;				/* le texte avant le % recontré*/
	t_flags			flags;  		    /* le flag */
    t_modifier      modifier;
	char			*expression; 	    /* l'expression entiere sans le % sign au debut */
	int				width;			    /* la taille minimale de l'output */
	char			type;			    /* le type du content */
	int				precision;		    /* la precision exigée en int */
	char			*s_val;			    /* la variable envoyé correspondant au type s recupéré depuis va_ap */
	int 			i_val;			    /* la variable envoyé correspondant au type d, i, o, c, u, x recupéré depuis va_ap */
	double			d_val;			    /* la variable envoyé correspondant au type g, e, f recupéré depuis va_ap */
	char			*buffer;		    /* la valeur final retourné */
	int				buffer_len;		    /* la longeur du buffer a afficher */
    t_data	        *next;		        /* la prochaine structure */
}		            t_data;

#endif