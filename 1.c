#include <stdio.h> 
#include <math.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
void task1(){
printf("char %zu\n", sizeof(char));
printf("short  %zu\n", sizeof(short ));
printf("int %zu\n", sizeof(int));
printf("float %zu\n", sizeof(float));
printf("double %zu\n", sizeof(double));
printf("long double %zu\n", sizeof(long double));
}

float task2(){
printf("right ans is %f\n",(5/2)*1.3);
}

void task3(){
printf("true is 1 \n");
printf("false is 0 \n");
}
// task 4 func
float tF(float  c ){
	float f;
	 f=(c*9)/5 +32;
	 return f;
}
float tR(float  c ){
	float f1;
	 f1=(c*4)/5;
	 return f1;
}
// end 4 task func
void kolvo(int x){
	int k = 0;
	int n;
	n=x;
	 while (n> 0) {
		k++;
		n/=10;
}
printf("kol-vo chifer v X =  %i\n",k);
}
void cross(int x) {
	
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if ( (i == j) || (i == x - j - 1) )   // если главная или побочная диагональ
		           printf("*");
		        else
		            printf(" ");;


  }
 printf("\n");;
 }
}
void risovanie(int x,int n) {

  int z = 1, s, c = 0,q,n1=x*2+1;
	switch(n) { 
	case 1 :
		for(int i=0;i<x;i++){
			for(int j=0;j<x;j++){
				if ( (i == j) || (i == x - j - 1) )   // если главная или побочная диагональ
				       printf("*");
				    else
				        printf(" ");;


	  }
	 printf("\n");;
	 }
	break;

	case 2 :
		for(int i = 0; i < n1; i++){
        for(int j = 0; j < n1; j ++){
            if(min(abs(n1 - i -1),abs(0 - i)) +
                  min(abs(n1 - j -1),abs(0 - j)) 
                        >= x && (i%2 != j %2)){
                printf("*");
            }
            else printf(" ");
       }
       printf("\n");
    } 
	break;
 }
}
int main(){
int x,n;
task1();
printf("\n/////////////New Task/////////////\n\n");
task2();
printf("\n/////////////New Task/////////////\n\n");
task3();
printf("\n/////////////New Task/////////////\n\n");
// task 4
for(float i=-5;i<=5;i=i+1.25){
printf("tC=%f tF=%f tR=%f\n",i,tF(i),tR(i));
}
printf("\n/////////////New Task/////////////\n\n");
printf("Vvedite x \n");
scanf("%d",&x);
printf("Vvedite 1<=n<=2 \n");
scanf("%d",&n);
kolvo(x);
printf("\n/////////////New Task/////////////\n\n");
risovanie(x,n);
printf("\n/////////////New Task/////////////\n\n");
return 0; 
} 
