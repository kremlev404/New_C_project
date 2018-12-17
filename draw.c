#include <stdio.h>
typedef unsigned int u_int;
typedef void (*Draw_Func_t)(int,char);

void Cross(int n, char sym){
	int j, i;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if((j == i) || (j == (n - i - 1)))
				printf("%c" , sym);
			else
				printf(" ");
		}
		printf("\n");
	}
return;
}
	
void Empty_Rhomb(int n, char sym){
	if (n % 2 == 1) {
		int j, i;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if( ((j + i) == (n/2)) || ((i + j) == (n - 1) + (n / 2)) || (j == i + (n/2)) || (i == j + (n/2)) )
					printf("%c", sym);
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	else 
		printf("Error you need to enter odd size\n");
return;
}

void Filled_Rhomb(int n, char sym){
	if ((n % 2) == 1) {
		int j, i, k, middle = 1;
		for(i=0;i<n;i++){

			for(j=(n-1);j>i;j--)
    			printf(" ");

    		for(int k=0;k<middle;k++)
       			printf("%c", sym); 
    		
    		printf("\n"); 
		    middle+=2;
		}
 		middle-=4;
 		for(i=1;i<n;i++){

			for(j=0;j<i;j++)
    			printf(" ");

    		for(k=0;k<middle;k++)
    			printf("%c", sym); 

   			printf("\n"); 
    		middle-=2;
		}	
  }	
	else 
		printf("Error you need to enter odd size\n");
return;
}

int main(){
	int type_of_fig, n;
	char sym;

	Draw_Func_t Draw_Func[3];
	Draw_Func[0] = Cross;
	Draw_Func[1] = Empty_Rhomb;
	Draw_Func[2] = Filled_Rhomb;
  
	printf("Enter symbol: ");
	scanf("%c", &sym);
	printf("\nEnter size : ");
	scanf("%d", &n);
	printf("\n0)\tCross\n");
	printf("1)\tEmpty_Rhomb\n");
	printf("2)\tFilled_Rhomb\n\n");
	printf("Choose figure_type :\n");
	scanf("%d", &type_of_fig);
	
	Draw_Func[type_of_fig](n,sym);

return 0;
}
