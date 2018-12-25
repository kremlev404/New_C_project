#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int n=1,i=0,flag=0;
	char c,ch_repl;

	FILE* iFile;
	FILE* replaces;
	FILE* oFile;

	iFile = fopen("1.txt", "r");
	oFile = fopen("2.txt", "w");
	replaces = fopen("replaces.txt", "r");
	if ((iFile == NULL)||(replaces == NULL)||(oFile == NULL))
	{
		fprintf(stderr, "Cannot open file ...\n");
		return -1;
	}

	
	
	while(fgetc(replaces) != EOF) //
 	{
 		n++;
	}
 	
	
	char* arr = (char*)malloc(n * sizeof(char));

	while(fgetc(replaces) != EOF) //
 	{
 		arr[i] = fgetc(replaces);
 		i++;
	}
 	i = 0;
	while ((fgetc(iFile)) != EOF)
	{
		c = fgetc(iFile);
		while ((fgetc(replaces)) != EOF)
		{
			if (c == arr[i]){
				putc(arr[i+1], oFile);
				flag = 1;
			}
			else 
				flag = 0;
			i++;
		}
		i = 0;	
		if ( flag == 0 )
			putc(c, oFile);
	}
	printf("\n");
	fclose(iFile);
	fclose(oFile);
	fclose(replaces);
	free(arr);
	arr = NULL;
return 0;
}
