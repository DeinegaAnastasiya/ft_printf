#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	while(s[i])
		i++;
	return (i);
}

void	test(char *s)
{
	char **m;
	int i;

	m = (char **)malloc(sizeof(char*) * ft_strlen(s) + 1);
	
}

int 	main(int argc, char **argv)
{
	if (argc == 2)
		str_capitalizer(argv[1]);
	write(1, "\n", 1);
	return (0);
}
