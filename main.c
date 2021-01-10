#include <stdio.h>

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
	printf("%s\n", ft_strcpy("coucou", "coucou"));
	return 0;
}
