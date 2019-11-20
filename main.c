#include "./src/malloc.h"

int	main()
{
	int		*test[10];
	int		i = 0;

	while (i < 100)
	{
		test[i] = malloc(sizeof(int));
		*test[i] = 42;
		printf("%d", *test[i]);
		i++;
	}
	return (0);
}
