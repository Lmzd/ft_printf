/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:32:24 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/08 08:23:20 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct		s_flags
{
	int				zero;
	int				hash;
	int				plus;
	int				dash;
	int				spaces;
}					t_flags;

typedef struct		s_modifier
{
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}					t_modifier;
typedef struct		s_data
{
	char			*text;
	char			*expression;
	int				width;
	int				wmalloc;
	int				precision;
	int				neg;
	int				null;
	char			type;
	wchar_t			value;
	char			*buffer;
	wchar_t			*wbuffer;
	t_flags			flags;
	t_modifier		modifier;
	int				error;
	struct s_data	*next;
}					t_data;

#endif
