/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:00:08 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/01/15 18:39:17 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_lstsize(t_list *lst);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *b, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *ch, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlen2(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/////////////////////////////////////////////////////////////////////////

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);

int		ft_printstr(char *str);
void	ft_put_ptr(intptr_t *num);
int		ft_ptr_len(intptr_t *num);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned	int num);
int		ft_hex_len(unsigned	int num);
int		ft_print_hex(unsigned int num, const char format);

char	*ft_itoa(int n);
int		len_nb(long nb);
int		ft_pointer(size_t pointer);

////////////////////////////////////////////////////////////////////////

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct l_list
{
	char			*content;
	struct l_list	*next;
}				k_list;

char	*get_next_line(int fd);

void	ft_read(int fd, k_list **stash);
void	ajt_reserve(k_list **stash, char *buf, int readed);
void	ligne(k_list *stash, char **line);
void	malloc_ligne(char **line, k_list *stash);
void	nv_reserve(k_list **stash);
void	free_reserve(k_list *stash);

int		nouvelle_ligne(k_list *stash);

k_list	*dernier_maillon(k_list *stash);

#endif
