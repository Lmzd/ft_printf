/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:40:09 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/05/10 17:46:08 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Find the regex length
*/

int	ft_get_regex_len(char **src)
{
	int 			len;
	int 			i;
	int				j;
	
	i = 0;
	len = 0;
	while ((*src)[i] != '\0')
	{
		j = 0;
		while (TYPES[j] != '\0')
		{
			if ((*src)[i] == TYPES[j])
				return (++len);
			j++;
		}
		i++;
		len++;
	}
	return (len);
}

/*
**	Find the regex in format
**	send string begin with % 
**  have to return a string with all the regex
*/

char	*ft_find_regex(char **src)
{
	char	*regex;	
	int 	len;

	len = ft_get_regex_len(src);
	regex = ft_strncut(src, len);
	return (regex);
}

/*
**	Push Back elem in the main list
*/

void	ft_append(t_data **lst, t_data *new)
{
	t_data	*list_tmp;

	list_tmp = *lst;
	if (list_tmp)
	{
		while (list_tmp->next)
			list_tmp = list_tmp->next;
		list_tmp->next = new;
		new->next = NULL;
	}
	else
	{
		list_tmp = new;
		new->next = NULL;
	}
}

int		ft_parser_get_precision(char *regex)
{
	int 	i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (regex[i] != '.')
		i++;
	i++;
	while (regex[i] >= 48 && regex[i++] <= 59)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (regex[i] != '.')
		i++;
	i++;
	j = 0;
	while (regex[i] >= 48 && regex[i] <= 59)
		res[j++] = regex[i++];
	res[j] = '\0';
	return (ft_atoi(res));
}


/*
**	Fill the options variable and type in a structure element
**	from regex
*/

t_data	*ft_parser_option_checker(t_data *elem)
{
	t_data 	*curr;
	int		len;
	char 	*regex;
	char	*width;

	curr = elem;
	regex = ft_strdup(curr->regex);
	if (!regex)
		return (curr);
	len = ft_strlen(regex);
	curr->type = regex[len - 1];
	curr->flags.plus = ft_strhas(regex, '+');
	curr->flags.moins = ft_strhas(regex, '-');
	curr->flags.hashtag = ft_strhas(regex, '#');
	curr->flags.spaces = ft_strhas(regex, ' ');
	curr->flags.zero = ft_strhas(regex, '0');
	if (ft_strhas(regex, '.'))
		curr->width = ft_parser_get_width(); /* Here */
		curr->preci = ft_parser_get_precision(regex);
	free(regex);
	return (curr);
}