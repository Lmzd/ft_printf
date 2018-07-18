/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:46:22 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/07/17 20:30:45 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_PARSER_H
# define FT_UTILS_PARSER_H

# include "./ft_printf.h" 

char	*ft_parser_find_regex(char **src);
int	    ft_parser_get_regex_len(char **src);
int		ft_parser_get_width(char *reg);
int		ft_parser_get_precision(char *regex);
t_data	*ft_parser_flags_checker(t_data *elem);
int		ft_parser_get_zero_flag_width(char *reg);

#endif

