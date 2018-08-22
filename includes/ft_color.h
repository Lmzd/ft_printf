/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 00:42:59 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/21 18:27:27 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# define DEFAULT    "\e[39m"
# define BLACK      "\e[30m"
# define RED        "\e[31m"
# define GREEN      "\e[32m"
# define YELLOW     "\e[33m"
# define BLUE       "\e[34m"
# define MAGENTA    "\e[35m"
# define CYAN       "\e[36m"
# define LGRAY      "\e[37m"
# define DGRAY      "\e[90m"
# define LRED       "\e[91m"
# define LGREEN     "\e[92m"
# define LYELLOW    "\e[93m"
# define LBLUE      "\e[94m"
# define LMAGENTA   "\e[95m"
# define LCYAN      "\e[96m"
# define WHITE      "\e[97m"
# define BOLD       "\e[1m"
# define ULINE      "\e[4m"
# define RESET      "\e[0m"

typedef struct	s_color
{
	char	*def;
	char	*col;
}				t_color;

t_color g_color[] =
{
	{"{def}", DEFAULT},
	{"{black}", BLACK},
	{"{red}", RED},
	{"{green}", GREEN},
	{"{yellow}", YELLOW},
	{"{blue}", BLUE},
	{"{mag}", MAGENTA},
	{"{cyan}", CYAN},
	{"{lgray}", LGRAY},
	{"{dgray}", DGRAY},
	{"{lred}", LRED},
	{"{lgreen}", LGREEN},
	{"{lyellow}", LYELLOW},
	{"{lblue}", LBLUE},
	{"{lmag}", LMAGENTA},
	{"{lcyan}", LCYAN},
	{"{white}", WHITE},
	{"{bold}", BOLD},
	{"{uline}", ULINE},
	{"{oec}", RESET},
	{0, 0}
};

#endif
