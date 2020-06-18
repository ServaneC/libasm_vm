/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schene <schene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:05:15 by servanechen       #+#    #+#             */
/*   Updated: 2020/05/20 13:12:05 by schene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int main()
{
	char	*s1 = "Hello World !";
	int		ret;
	char	s2[14];
	char	s3[14];
//	char	*null;
	char	*empty;
	char	*cmp = "Hello Earth !";
	char	*buf;
	int		fd;
	char	*up;

//	null = NULL;
	empty = "";
	printf("------strlen--&--ft_strlen-----\n");
	printf("str = [%s]\nstrlen = %zu\nft_strlen = %zu\n", s1, strlen(s1), ft_strlen(s1));
	// strlen on an empty str
	printf("str = [%s]\nstrlen = %zu\nft_strlen = %zu\n", empty, strlen(empty), ft_strlen(empty));

	// a strlen of a null str should result to a segfault
	//printf("str = [%s]\nstrlen = %zu\n", null, strlen(null));
	//printf("str = [%s]\nft_strlen = %zu\n", null, ft_strlen(null));


	printf("\n------strcpy--&--ft_strcpy-----\n");
	printf("str = [%s]\nstrcpy = [%s]\nft_strcpy = [%s]\n", s1, strcpy(s2, s1), ft_strcpy(s3, s1));
	
	// a strcpy to or from an empty str result to an error
	//printf("str = [%s]\nstrcpy = [%s]\n", s1, strcpy(empty, s1));
	//printf("str = [%s]\nft_strcpy = [%s]\n", s1, ft_strcpy(empty, s1));
	
	// a strcpy to or from a null str result to a segfault
	//printf("str = [%s]\nstrcpy = [%s]\n", s1, strcpy(s1, null));
	//printf("str = [%s]\nft_strcpy = [%s]\n", s1, ft_strcpy(s1, null));

	printf("\n------strcmp--&--ft_strcmp-----\n");
	printf("s1 = [%s] and s2 = [%s]\nstrcmp = [%d]\nft_strcmp = [%d]\n", s1, cmp, strcmp(s1, cmp), ft_strcmp(s1, cmp));
	printf("s1 = [%s] and s2 = [%s]\nstrcmp = [%d]\nft_strcmp = [%d]\n", s1, s1, strcmp(s1, s1), ft_strcmp(s1, s1));

	// strcmp with an empty string
	printf("s1 = [%s] and s2 = [%s]\nstrcmp = [%d]\nft_strcmp = [%d]\n", s1, empty, strcmp(s1, empty), ft_strcmp(s1, empty));

	// a strcmp with a null str should result to a segfault
	//printf("s1 = [%s] and s2 = [%s]\nstrcmp = [%d]\n", s1, null, strcmp(s1, null));
	//printf("s1 = [%s] and s2 = [%s]\nft_strcmp = [%d]\n", s1, null, ft_strcmp(s1, null));
	printf("\n------write--&--ft_write-----\n");
	printf("<--write");
	ret = write(1, s1, strlen(s1));
	//ret = write(-3, s1, strlen(s1));
	printf("\nerrno = %d and ret = %d\n", errno, ret);
	printf("\n<--ft_write\n");
	//ret = ft_write(-3, s1, strlen(s1));
	ret = ft_write(1, s1, strlen(s1));
	printf("\nerrno = %d and ret = %d\n", errno, ret);
	errno = 0;
	printf("\n-----------ft_read-----------\n");
	fd = open("text.txt", O_RDONLY);
	if (!(buf = malloc(sizeof(char)*66)))
		return(-1);
	//fd = -3;
	ft_read(fd, buf, 66);
	printf("ft_read = [%s]\nerrno = %d\n", buf, errno);
	close(fd);
	printf("\n-----------ft_strdup-----------\n");
	up = ft_strdup(buf);
	printf("ft_strdup of the str from ft_read test:\n[%s]\n", up);
	free(up);
	up = ft_strdup(empty);
	printf("\nft_strdup of an empty str:\n[%s]\n", up);
	free(up);
	// a strdup of e null str result to a segfault
	//up = ft_strdup();
	//printf("ft_strdup of an empty str:\n[%s]\n", up);
	//free(up);
	free(buf);
	return(0);
}
