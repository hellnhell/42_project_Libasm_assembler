/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:34:07 by emartin-          #+#    #+#             */
/*   Updated: 2020/09/02 20:24:26 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>


void	check_ft_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n\n============== LEN =============\n\n");
	printf("%-20s: \"%s\"\n","Empty", empty);
	printf("%-20s: \"%lu\"\n", "libc", strlen(empty));
	printf("%-20s: \"%zu\"\n", "libasm", ft_strlen(empty));
	printf("%-20s: \"%s\"\n","hello_world", hello_world);
	printf("%-20s: \"%lu\"\n", "libc", strlen(hello_world));
	printf("%-20s: \"%zu\"\n", "libasm", ft_strlen(hello_world));
	printf("%-20s: \"%s\"\n","Empty", alphabet);
	printf("%-20s: \"%lu\"\n", "libc", strlen(alphabet));
	printf("%-20s: \"%zu\"\n", "libasm", ft_strlen(alphabet));
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}


void	check_ft_strcpy()
{
	char buffer[30];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n\n========== CPY ===========\n\n");
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));	
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));	
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));	
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");
}

void	check_ft_strcmp()
{
	char	*s1 = "Hi";
	char	*s2 = "Checkin";
	char	*empty = "";
	

	printf("\n\n============== CMP =============\n\n");
	printf("Diferent sentence :\n Libasm : %d\n", ft_strcmp(s1, s2));
	printf(" Libc : %d\n", strcmp(s1, s2));
	printf("Same sentence :\n Libasm : %d\n", ft_strcmp(s1, s1));
	printf(" Libc : %d\n", strcmp(s1, s1));
	printf("NULL :\n Libasm : %d\n", ft_strcmp(empty, s2));
	printf(" Libc : %d\n", strcmp(empty, s2));
}

void	check_ft_read()
{
	char	buffer[900];
	int 	fd;
	int 	rlibc;
	int		rlibasm;
	

	printf("\n\n============== READ =============\n\n");
	printf("====Open field try ====>\n");
	fd = open("main.c", O_RDONLY);
	rlibc = read(fd, buffer, 50);
	rlibasm = ft_read(fd, buffer, 50);
	printf("libc : [%d]\n", rlibc);
	printf("libasm : [%d]\n", rlibasm);
	close(fd);
	printf("\n");

	printf("====Second try ====>\n");
	fd = open("hola", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	printf("libc : [%d]\n", rlibc);
	close(fd);
	
	fd = open("hola", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	printf("libasm : [%d]\n", rlibasm);
	close(fd);	
	

	printf("====Crash try ====>\n");
	fd = open("wrong", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	printf("libc : [%d]\n", rlibc);
	close(fd);
	
	fd = open("wrong", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	printf("libasm : [%d]\n", rlibasm);
	close(fd);	
	
	/*printf("====Screen try ====>\n");
	rlibc = read(0, buffer, 890);
	printf("libc : [%d]\n", rlibc);
	close(fd);
	
	rlibasm = ft_read(0, buffer, 890);
	printf("libasm : [%d]\n", rlibasm);
	close(fd);*/
	
}

void	check_ft_write()
{
	char	buffer[900];
	int 	fd;
	int 	rlibc;
	int		rlibasm;

	printf("\n\n============== WRITE =============\n\n");
	printf("====First try ====>\n");
	fd = open("hola", O_WRONLY);
	rlibc = write(fd, buffer, 890);
	printf("libc : [%d]\n", rlibc);
	close(fd);
	
	fd = open("hola", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 890);
	printf("libasm : [%d]\n", rlibasm);
	close(fd);
	
	printf("====Crash try ====>\n");
	fd = open("wrong", O_WRONLY);
	rlibc = write(fd, buffer, 890);
	printf("libc : [%d]\n", rlibc);
	close(fd);
	
	fd = open("wrong", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 890);
	printf("libasm : [%d]\n", rlibasm);
	close(fd);	
	
	printf("====Screen try ====>\n");
	rlibc = write(1, buffer, 890);
	printf("libc : [%d]\n", rlibc);
	close(fd);
	
	rlibasm = ft_write(1, buffer, 890); 
	printf("libasm : [%d]\n", rlibasm);
	close(fd);	
}

void	check_ft_strdup()
{

	char *hello_world = "Hello world !";
	char *empty = "";
	char *save;
	char *save2;
	
	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	printf("%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
}


int		main(void)
{
	check_ft_strlen();
	check_ft_strcpy();
	check_ft_strcmp();
	check_ft_read();
	check_ft_write();
	check_ft_strdup();
	return (0);
}
