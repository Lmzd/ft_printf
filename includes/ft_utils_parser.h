/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:46:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:49:44 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_PARSER_H
# define FT_UTILS_PARSER_H

# include "./libftprintf.h"

/*
**  Parser
*/
char	*ft_parser_find_regex(char **src);
int		ft_parser_get_regex_len(char **src);
int		ft_parser_get_width(char *reg);
int		ft_parser_get_width_precision(char *str);
int		ft_parser_get_precision(char *regex);
int		ft_parser_get_zero_flag_width(char *reg);
int		ft_parser_get_zero_flag_width_precision(char *reg);
void	ft_parser_options_checker(t_data *elem);
void	ft_parser_get_text_and_expression(t_data *elem, char **str);
void	ft_parser_put_default(t_data *elem);

#endif
