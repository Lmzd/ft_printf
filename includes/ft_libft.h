/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:47:11 by lmazeaud          #+#    #+#             */
/*   Updated: 2018/08/07 07:44:14 by lmazeaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** @brief Affiche le caractère c sur la sortie standard.
**
** @param Le caractère à afficher.
** @return Rien.
**
** @author lmazeaud
*/
void				ft_putchar(char c);

/*
** @brief  Calcule la longueur de la chaîne de caractères s,
**			sans compter l'octet nul « \0 » final.
**
** @param Chaine de caratères à calculé
** @return Renvoie le nombre de caractères dans la chaîne s
**
** @author lmazeaud
*/
size_t				ft_strlen(const char *str);

/*
** @brief renvoie un pointeur sur une nouvelle chaîne de caractères
**			qui est dupliquée depuis s
**
** @param chaîne de caractères à dupliquer
** @return chaine de caratères dupluquée
**
** @author lmazeaud
*/
char				*ft_strdup(const char *s);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_islower(int c);

int					ft_isupper(int c);

int					ft_islower(int c);

void				ft_memdel(void **ap);

void				*ft_memset(void *str, int c, size_t n);

void				ft_bzero(void *s, size_t n);

char				*ft_strcat(char *dest, const char *src);

int					ft_strhas_digit(const char *str);

int					ft_strhas_str(const char *str, const char *find);

char				*ft_strtoupper(char *str);

int					ft_toupper(int c);

void				ft_putwchar(wchar_t wc);

void				ft_putstr(const char *str);

void				*ft_memalloc(size_t size);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strcut(char **src, int c);

char				*ft_strncut(char **src, size_t n);

char				*ft_cutstr(char *src, int c);

int					ft_strhas_char(char *str, int c);

char				*ft_strtoupper(char *str);

char				*ft_itoa_base_intmax(intmax_t n, int base);

char				*ft_itoa_base_uintmax(uintmax_t n, int base);

int					ft_strhas_zero(char *str, int c);

char				*ft_itoa_intmax(intmax_t nb);

char				*ft_strreplace(char *str, int letter, size_t index);

intmax_t			ft_abs_intmax(intmax_t value);

size_t				ft_strwlen(wchar_t *str);

size_t				ft_wcharlen(wchar_t c);

char				*ft_fillit(char c, size_t n);

void				ft_wbzero(wchar_t *str, size_t nb);

#endif
