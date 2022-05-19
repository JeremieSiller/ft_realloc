#include "ft_realloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	test(void)
{
	int	*ptr;
	int	i;

	ptr = ft_malloc(10000);
	i = 1;
	while (i < 100)
	{
		ptr = ft_realloc(ptr, i * 10000);
		i++;
	}
	ft_free(ptr);
}

int	main(void)
{
	test();
	system("leaks a.out");
	return (0);
}
