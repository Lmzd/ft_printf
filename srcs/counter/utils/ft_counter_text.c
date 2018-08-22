/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counter_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 06:23:32 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/21 18:22:06 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libftprintf.h"
#include "../../../includes/ft_color.h"

char	*ft_counter_create_new_text(char *text)
{
	int	i;
	int	nb;
	int	len;

	i = -1;
	len = ft_strlen(text);
	nb = 0;
	while (text[++i])
		if (text[i] == '{')
			nb++;
	return (ft_strnew(len + (nb * 6)));
}

char	*ft_counter_get_color(char *text, char *def)
{
	int	i;

	i = -1;
	while (*text != '}')
	{
		def[++i] = *text;
		text++;
	}
	def[++i] = *text;
	def[++i] = '\0';
	return (text);
}

char	*ft_counter_color_router(char *new_text, char *def)
{
	int	i;
	int	j;

	i = 0;
	while (g_color[i].def)
	{
		if (!ft_strcmp(def, g_color[i].def))
		{
			j = -1;
			while (g_color[i].col[++j])
			{
				*new_text = g_color[i].col[j];
				new_text++;
			}
		}
		i++;
	}
	return (new_text);
}

int		ft_counter_text(t_data *elem)
{
	char	*text;
	char	*def;
	char	*new_text;
	char	*res;

	if (!ft_strhas_char(elem->text, '{') || !ft_strhas_char(elem->text, '}')
	|| ft_strlen(elem->text) < 4)
		return (ft_strlen(elem->text));
	text = elem->text;
	new_text = ft_counter_create_new_text(text);
	res = new_text;
	while (*(text)++)
	{
		if (*text == '{')
		{
			def = ft_strnew(8);
			text = ft_counter_get_color(text, def);
			new_text = ft_counter_color_router(new_text, def);
		}
		else
			*(new_text)++ = *text;
	}
	free(elem->text);
	elem->text = res;
	return (ft_strlen(res));
}
