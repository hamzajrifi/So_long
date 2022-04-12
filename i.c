#include <stdio.h>
int main()
{
	char **arr = malloc(sizeof(char *) * 11);
	int  i= 0;

	while(i < 10)
	{
		arr[i] = strdup("ilyass");
		i++;
	}
	arr[i] = NULL;
	i = 0;
	while(arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}