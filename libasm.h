/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:56:06 by emartin-          #+#    #+#             */
/*   Updated: 2020/08/24 19:51:25 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define KRED  "\x1B[31m"
#define KNRM  "\x1B[0m"

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char * dst, const char * src);
int			ft_strcmp(const char *s1, const char *s2);
char *		ft_strdup(const char *s1);
size_t		ft_read(int fd, char *buffer, size_t t);
size_t		ft_write(int fd, char *buffer, size_t t);

#endif