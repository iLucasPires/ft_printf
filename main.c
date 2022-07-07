#include "./includes/ft_printf.h"

int	main(void)
{
	int size;
	int size2;
	int a = 10;
	int *b = &a;
	size = ft_printf(" %%   %%   %% ");
	printf("\n");
	size2 = printf(" %%   %%   %% ");
	printf("\n");
	printf("meu : %d\n", size);
	printf("dele: %d\n", size2);
	return (0);
}