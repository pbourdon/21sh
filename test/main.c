#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

char	*ft_exclamation_diez(char *arg);

int		main(void)
{
	printf("%s", ft_exclamation_diez("ALPHA BETA DELTA ~ ! ADAWDWAD  $ # !#"));
	return (0);
}
