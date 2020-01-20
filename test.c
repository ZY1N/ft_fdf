#include "./libft/libft.h"
#include <stdio.h>

void otherthing(char *s)
{
	s[0] = 'a';

}


int main()
{
	char *s = "ad s k l fja sdkl f j k l asdfjnklas";
	char **split;

	split = ft_strsplit(s, ' ');
	for(int i = 0; split[i]; i++)
	{
		otherthing(split[i]);
		//free(split[i]);
		printf("%s ", split[i]);
		free(split[i]);
	}
	printf("test");
	write(1, "here", 4);
	free(split);
}
