/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:24:34 by zyasa             #+#    #+#             */
/*   Updated: 2023/02/10 14:45:06 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
int		is_n_gnl(char *str);
int		ft_strlen_gnl(char *str);
int		ft_strcpy_gnl(char *s1, char *s2);

#endif
