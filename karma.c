#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
typedef unsigned int u_int;

typedef struct User
{
	int id;
	char nick[51];
	int karma;
} User;

int intCmpKarma(const void* pa , const void* pb ){ 
	const int a = ((User*)pa)->karma-((User*)pb)->karma;
return a;
}

int intCmpNick(const void* pa , const void* pb ){ 
	return strcmp((((User*)pa)->nick), (((User*)pb)->nick));
}

void Choose_Type_Of_Sort(User* arr,u_int n,u_int tp){
	switch(tp) {
		case 1:
			printf(" You Choose Karma Sort\n");
			qsort(arr, n, sizeof(User), intCmpKarma); 
			for(int i = 0; i < n; i++) {
				printf("%d)\t", arr[i].id);
				printf("%s \t", arr[i].nick);
				printf("%d \n", arr[i].karma);
			}
			break;
		case 2:
			printf(" You Choose Nick Sort\n"); 
			qsort(arr, n, sizeof(User), intCmpNick);
			for(int i = 0; i < n; i++) {
				printf("%d)\t", arr[i].id);
				printf("%s \t", arr[i].nick);
				printf("%d \n", arr[i].karma);
			} 
	}
return;
}

int main(){  
	u_int n, tp, i, i_id; // number of users
	srand(time(NULL));
	printf("Enter number of users: ");
	scanf("%u", &n);
	printf("Choose type of sort '1'-Karma '2'-Nick : ");
	scanf("%u", &tp);
	User* arr = (User*)malloc(n * sizeof(User));

	for(i = 0; i < n; i++){  
		system("clear");
		i_id = i + 1;                
		arr[i].id = i_id;
		arr[i].karma = rand() % 1000 + 1;
		printf("%d) Enter Nick : ", i_id);
		scanf("%s", arr[i].nick);
	}

	Choose_Type_Of_Sort(arr,n,tp);

	free(arr);
	arr = NULL;
	return 0;
}
