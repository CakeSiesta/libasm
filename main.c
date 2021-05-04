#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

# define BUFF_SIZE 500

extern size_t	ft_strlen(char const *str);
extern char	*ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

void	check_strlen(void)
{
	printf("STRLEN CHECK \n\n");
	printf("%zu\n", ft_strlen("123456789"));
	printf("%zu\n", strlen("123456789"));
}

void	check_strcpy(void)
{
	printf("STRCPY CHECK \n\n");
	char s[20] = "coucou";
	char d[20] = "salut";
	char s2[20] = "coucou";
	char d2[20] = "salut";

	printf("source before ==[%s]\n", s);
	printf("destin before ==[%s]\n", d);
	ft_strcpy(s2, d2);
	printf("source after  ==[%s]\n", s);
	printf("destin after  ==[%s]\n", d);
}

void	check_strcmp(void)
{
	printf("STRCMP CHECK \n\n");
	char	str1[20] = "abcd", str2[20] = "abCd", str3[20] = "abcd";
	int	result;

	result = ft_strcmp(str1, str2);
	printf("ft_strcmp(str1, str2) = [%d]\n", result);
	result = strcmp(str1, str2);
	printf("strcmp(str1, str2) = [%d]\n", result);

	result = ft_strcmp(str1, str3);
	printf("\n\nft_strcmp(str1, str2) = [%d]\n", result);
	result = strcmp(str1, str3);
	printf("strcmp(str1, str2) = [%d]\n", result);
}

void	check_write(void)
{
	printf("WRITE CHECK \n\n");
	ft_write(1,"qwertyuiopasdfghjklzxcvbnm",25);
	printf("\n");
	write(1,"qwertyuiopasdfghjklzxcvbnm",25);
}

void	check_read(void)
{
	ssize_t	a;
	int	fd;
	char	buf[BUFF_SIZE+1];

	printf("READ CHECK \n\n");
	fd = -1;
	a = ft_read(fd, buf, BUFF_SIZE);
	printf("fd = %d, %zd, error : %s\n", fd, a, strerror(errno));
	a = read(fd, buf, BUFF_SIZE);
	printf("fd = %d, %zd, error : %s\n", fd, a, strerror(errno));
	printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	fd = open("main.c", O_RDONLY);
	a = ft_read(fd, buf, BUFF_SIZE);
	printf("fd = %d, %zd, str : %s\n", fd, a, buf);
	printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
	a = read(fd, buf, BUFF_SIZE);
	printf("fd = %d, %zd, str : %s\n", fd, a, buf);
}

void	check_strdup(void)
{
	printf("STRDUP CHECK \n\n");
	char		*str;
	char		f[] = "h";
	char		s[] = "hello";
	char		t[] = "";

	printf("[+] STRDUP [+]\n");
	printf("[-] Str init [-]\n");
	str = ft_strdup(f);
	printf("[-] Str after strdup1 (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	free(str);
	str = strdup(f);
	printf("[-] Str after strdup1 real (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	free(str);
	str = ft_strdup(s);
	printf("[-] Str after strdup2 (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	free(str);
	str = strdup(s);
	printf("[-] Str after strdup2 real (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	free(str);
	str = ft_strdup(t);
	printf("[-] Str after strdup3 (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	free(str);
	str = strdup(t);
	printf("[-] Str after strdup3 real (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	free(str);
	printf("[+] END OF STRDUP [+]\n");

}

int	main(void)
{
	check_strlen();
	printf("\n==================\n");

	check_strcpy();
	printf("\n==================\n");

	check_strcmp();
	printf("\n==================\n");

	check_write();
	printf("\n==================\n");

	check_read();
	printf("\n==================\n");

	check_strdup();
	printf("\n==================\n");

}
