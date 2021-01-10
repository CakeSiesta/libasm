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
	char s[] = "coucou";
	char d[] = "salut";

	printf("%s\n", s);
	ft_strcpy(s, d);
	printf("%s\n", s);
	return 0;
}
