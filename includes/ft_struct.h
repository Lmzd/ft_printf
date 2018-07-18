/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pblouin <pblouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:32:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/18 17:33:58 by pblouin          ###   ########.fr       */
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

typedef struct		s_data
{
    char 			*text;				/* le texte avant le % recontré*/
	t_flags			flags;			    /* le flag */
	char			*expression; 	    /* l'expression entiere sans le % sign au debut */
	int				width;			    /* la taille minimale de l'output */
	char			type;			    /* le type du content */
	int				precision;		    /* la precision exigée en int */
	void			*value;		    	/* la variable envoyé correspondant au type demandé recupéré depuis va_ap */
	char			*buffer;		    /* la string finale retournée */
	int				buffer_len;		    /* la longeur du buffer a afficher */
    struct s_data	*next;		        /* la prochaine structure */
}		            t_data;

#endif