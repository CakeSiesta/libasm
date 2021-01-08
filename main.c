#include <stdio.h>

extern size_t	ft_strlen(char const *str);

int	main()
{
	printf("%zu\n", ft_strlen("abc"));
	return (0);
}
