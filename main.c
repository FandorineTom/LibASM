/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorthmo <snorthmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:56:01 by snorthmo          #+#    #+#             */
/*   Updated: 2020/11/02 12:09:11 by snorthmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);

int		main(void)
{
	int		fd;
	int		fd1;
	char	*s1 = "normal string";
	char	*s2 = "";
	char	*s3 = "long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long long long long long long long long long long\
	long long long long long long long";
	char	s4[1000];
	char	*s5 = "It was a feature peculiar to the colonial wars of North America, that the toils and dangers of the wilderness were to be encountered before the adverse hosts could meet. A wide and apparently an impervious boundary of forests severed the possessions of the hostile provinces of France and England.";
	int		res;

	printf("	\x1B[34mSTRLEN_TESTS\n\x1B[0m");
	printf("      MY: \x1B[33mnormal\x1B[0m string res for strlen: %zu\n", ft_strlen(s1));
	printf("ORIGINAL: \x1B[33mnormal\x1B[0m string res for strlen: %zu\n\n", strlen(s1));
	printf("      MY: \x1B[33mempty\x1B[0m string res for strlen: %zu\n", ft_strlen(s2));
	printf("ORIGINAL: \x1B[33mempty\x1B[0m string res for strlen: %zu\n\n", strlen(s2));
	printf("      MY: \x1B[33mlong\x1B[0m string res for strlen: %zu\n", ft_strlen(s3));
	printf("ORIGINAL: \x1B[33mlong\x1B[0m string res for strlen: %zu\n\n", strlen(s3));
	
	printf("	\x1B[34mSTRCPY_TESTS\n\x1B[0m");
	printf("      MY:\x1B[33mdst befory copy(normal)\x1B[0m: |%s| \x1B[32mdst after copy\x1B[0m: |%s|\n", s4, ft_strcpy(s4, s1));
	printf("ORIGINAL:\x1B[33mdst befory copy(normal\x1B[0m: |%s| \x1B[32mdst after copy\x1B[0m: |%s|\n\n", s4, strcpy(s4, s1));
	printf("      MY:\x1B[33mdst befory copy(empty)\x1B[0m: |%s| \x1B[32mdst after copy\x1B[0m: |%s|\n", s4, ft_strcpy(s4, s2));
	printf("ORIGINAL:\x1B[33mdst befory copy(empty)\x1B[0m: |%s| \x1B[32mdst after copy\x1B[0m: |%s|\n\n", s4, strcpy(s4, s2));
	printf("      MY:\x1B[33mdst befory copy(long)\x1B[0m: |%s| \x1B[32mdst after copy\x1B[0m: |%s|\n", s4, ft_strcpy(s4, s5));
	printf("ORIGINAL:\x1B[33mdst befory copy(long)\x1B[0m: |%s| \x1B[32mdst after copy\x1B[0m: |%s|\n\n", s4, strcpy(s4, s5));

	printf("	\x1B[34mSTRCMP_TESTS\n\x1B[0m");
	printf("      MY: comparison between 2 \x1B[33mnormal\x1B[0m strings res: %d\n", ft_strcmp(s1, s5));
	printf("ORIGINAL: comparison between 2 \x1B[33mnormal\x1B[0m strings res: %d\n\n", strcmp(s1, s5));
	printf("      MY: comparison between 2 switched \x1B[33mnormal\x1B[0m strings res: %d\n", ft_strcmp(s5, s1));
	printf("ORIGINAL: comparison between 2 switched \x1B[33mnormal\x1B[0m strings res: %d\n\n", strcmp(s5, s1));
	printf("      MY: between \x1B[33mnormal\x1B[0m and \x1B[33mempty\x1B[0m strings: %d\n", ft_strcmp(s1, s2));
	printf("ORIGINAL: between \x1B[33mnormal\x1B[0m and \x1B[33mempty\x1B[0m strings: %d\n\n", strcmp(s1, s2));
	printf("      MY: between \x1B[33mempty\x1B[0m and \x1B[33mnormal\x1B[0m strings: %d\n", ft_strcmp(s2, s1));
	printf("ORIGINAL: between \x1B[33mempty\x1B[0m and \x1B[33mnormal\x1B[0m strings: %d\n\n", strcmp(s2, s1));
	printf("      MY: comparison between 2 \x1B[33mempty\x1B[0m strings res: %d\n", ft_strcmp(s2, s2));
	printf("ORIGINAL: comparison between 2 \x1B[33mempty\x1B[0m strings res: %d\n\n", strcmp(s2, s2));

	printf("	\x1B[34mWRITE_TESTS\x1B[0m\n");
	res = ft_write(1, "      MY: normal string\n", 24);
	printf("	\x1B[33mreturn value\x1B[0m = %d\n", res);
	res = write(1, "ORIGINAL: normal string\n", 24);
	printf("	\x1B[33mreturn value\x1B[0m = %d\n\n", res);
	fd = open("test_file.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	res = ft_write(fd, "test string\n", 12);
	printf("\x1B[33mreturn value\x1B[0m for normal fd = %d\n", res);
	fd1 = open("wrong_file.txt", O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR);
	res = ft_write(fd1, "test string\n", 12);
	printf("\x1B[33mreturn value\x1B[0m for wrong fd = %d\n", res);
	printf("\terror code %d\n\n", errno);
	printf("      MY: \x1B[33mstring with NULL\x1B[0m res: %zd and the error code is %d\n", ft_write(fd1, NULL, 12), errno);
	printf("ORIGINAL: \x1B[33mstring with NULL\x1B[0m res: %zd and the error code is %d\n\n", write(fd1, NULL, 12), errno);
	printf("      MY: \x1B[33mfd that doesnt exist\x1B[0m: %zd and the error code is %d\n", ft_write(6, NULL, 12), errno);
	printf("ORIGINAL: \x1B[33mfd that doesnt exist\x1B[0m: %zd and the error code is %d\n\n", write(6, NULL, 12), errno);
	close(fd);
	close(fd1);
	return (0);
}