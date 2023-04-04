/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:42:50 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/04 23:28:47 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list {
  void *content;
  struct s_list *next;
} t_list;

// LIBFT

// ASCII Functions
/**
 * @brief Check if the given number corresponds to an alphabetic ASCII
 * character.
 *
 * @param c int
 * @return 0 if false, 1 if true
 */
int ft_isalpha(int c);

/**
 * @brief Check if the given number corresponds to a numeric ASCII character.
 *
 * @param c int
 * @return 0 if false, 1 if true
 */
int ft_isdigit(int c);

/**
 * @brief Check if the given number corresponds to an
 * 	alphanumeric ASCII character.
 *
 * @param c int
 * @return 0 if false, 1 if true
 */
int ft_isalnum(int c);

/**
 * @brief Check if the given number corresponds to an ASCII character.
 *
 * @param c int
 * @return 0 if false, 1 if true
 */
int ft_isascii(int c);

/**
 * @brief Check if the given number corresponds to a printable ASCII character.
 *
 * @param c int
 * @return 0 if false, 1 if true
 */
int ft_isprint(int c);

// String Functions

/**
 * @brief Calculate the length of a string.
 *
 * @param s const char *
 * @return size of string up to '\0'
 */
size_t ft_strlen(const char *s);

/**
 * @brief Copies up to 'size' - 1 characters from the NUL-terminated string
 * 'src' to 'dst', NUL-terminating the result.
 *
 * @param dst char *
 * @param src const char *
 * @param size size_t
 * @return The total length of the string it tried to
 * create (length of 'src').
 */
size_t ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string 'src' to the end of 'dst'.
 * It will appends at most 'size' - strlen('dst') - 1 bytes, NUL-terminating
 * the result.
 *
 * @param dst char *
 * @param src const char *
 * @param size size_t
 * @return The inital length of 'dst' plus the length of 'src'
 */
size_t ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Creates a new string which is a duplicate of 's'.
 *
 * @param s const char *
 * @return A pointer to the duplicated string, or NULL if insufficient
 *  memory was available.
 */
char *ft_strdup(const char *s);

/**
 * @brief Returns a pointer to the first occurence of the character 'c' in
 * the string 's'.
 *
 * @param s const char *
 * @param c int
 * @return A pointer to the matched character or NULL if the character is
 * not found.
 */
char *ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurence of the charater 'c' in
 * the string 's'.
 *
 * @param s const char *
 * @param c int
 * @return A pointer to the matched character or NULL if the character is
 * not found.
 */
char *ft_strrchr(const char *s, int c);

/**
 * @brief Returns a integer showing the result of the comparison:
 * 
 * - 0 if the strings are identical.
 * 
 * - a negative number if s1 is less than s2.
 * 
 * - a positive number if s1 is greater than s2.
 * 
 * @param s1 
 * @param s2 
 * @return int 
 */
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char *));
int ft_tolower(int c);
int ft_toupper(int c);

void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
int ft_atoi(const char *ptr);
void *ft_calloc(size_t nmemb, size_t size);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// get_next_line
int ft_findchar(char *str, char c);
char *get_after_nl(char *s);
char *get_before_nl(char *s);
char *find_new_line(char *str, int fd);
char *ft_read(int fd);
char *get_next_line(int fd);

// ft_printf
int ft_printf(const char *str, ...);
int valid_format(char c);
int ft_convert_hex(unsigned long arg, int state);
int printf_decoder(char c, va_list args);
int print_format(char c, va_list args);
int format_c(va_list args);
int format_s(va_list args);
int format_p(va_list args);
int format_d(va_list args);
int format_i(va_list args);
int format_u(va_list args);
int format_x_small(va_list args);
int format_x_big(va_list args);
int ft_uitoa(unsigned int num);
int ft_hex_len(unsigned long num);
int ft_get_int_size(unsigned int num);

#endif
