/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:46:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/21 15:19:46 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_PARSER_H
# define FT_UTILS_PARSER_H

# include "./ft_printf.h" 

/*
**  Parser
*/
char	*ft_parser_find_regex(char **src);
int	    ft_parser_get_regex_len(char **src);
int		ft_parser_get_width(char *reg);
int		ft_parser_get_precision(char *regex);
t_data	*ft_parser_options_checker(t_data *elem);
int		ft_parser_get_zero_flag_width(char *reg);
t_data  *ft_parser_get_text_and_expression(t_data *elem, char **str);
void    ft_parser_put_default(t_data *elem);

/*
**  Va_arg
*/
t_data  *ft_parser_va_arg_get_string_arg(t_data *elem, va_list ap);
t_data  *ft_parser_va_arg_get_double_arg(t_data *elem, va_list ap);
t_data  *ft_parser_va_arg_get_int_arg(t_data *elem, va_list ap);
t_data  *ft_parser_va_arg_get_argument(t_data *elem, va_list ap);

#endif

