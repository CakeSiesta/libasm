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
	printf("%zu\n", ft_strlen("123456789"));
	printf("%zu\n", strlen("123456789"));
}

void	check_strcpy(void)
{
	char s[] = "couc";
	char d[] = "salut";

	printf("source before ==[%s]\n", s);
	printf("destin before ==[%s]\n", d);
	ft_strcpy(s, d);
	printf("source after  ==[%s]\n", s);
	printf("destin after  ==[%s]\n", d);
}

void	check_strcmp(void)
{
	char	str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
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
	ft_write(1,"qwertyuiopasdfghjklzxcvbnm",25);
	printf("\n");
	write(1,"qwertyuiopasdfghjklzxcvbnm",25);
}

void	check_read(void)
{
	ssize_t	a;
	int	fd;
	char	buf[BUFF_SIZE+1];

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
	char		*str;
	char		f[] = "h";
	char		s[] = "hello";
	char		t[] = "";

	printf("[+] STRDUP [+]\n");
	printf("[-] Str init [-]\n");
	str = ft_strdup(f);
	printf("[-] Str after strdup (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	str = ft_strdup(s);
	printf("[-] Str after strdup (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
	str = ft_strdup(t);
	printf("[-] Str after strdup (\"%s\") %d [-]\n", str, (int)ft_strlen(str));
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
