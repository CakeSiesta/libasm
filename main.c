#include <stdio.h>
#include <string.h>

//extern size_t	ft_strlen(char const *str);
//
//int	main()
//{
//	printf("%zu\n", ft_strlen("123456789"));
//	return (0);
//}

extern char	*ft_strcpy(char *dest, const char *src);

int	main(void)
{
	char s[] = "couc";
	char d[] = "salut";

	printf("source before ==[%s]\n", s);
	printf("destin before ==[%s]\n", d);
	ft_strcpy(s, d);
	printf("source after  ==[%s]\n", s);
	printf("destin after  ==[%s]\n", d);
	return 0;
}
