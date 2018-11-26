#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h> 
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef enum Direction {up,down,right,left} Direction;
u_short Field[4][4];
u_short CurX, CurY;

//Создание игровой площадки 
void CreateField() {
	u_short arr[16], n, i, buf, k = 0; 
	bool flag = false ;
	srand(time(NULL)); 
	for (n = 0; n < 16; ) { 
		flag = false;
		buf =  rand() % 16 + 1 ;
			for (i = 0; i < n; i++) { 
				if (arr[i] == buf) { 
					flag = true; 
					break; 
				} 
			} 
		if (!flag) { 
			arr[n] = buf; 
			n++; 
		} 
	} 
	for (n = 0; n < 4; n++) 
		for (i = 0; i < 4; i++) { 
			Field[n][i] = arr[k]; 
			k++; 
		} 
	Field[3][3] = 0;
	CurX = 3; CurY = 3;
return; 
} 

// Организация перемещений
void Move(Direction dir) {
	switch(dir) { 
		case up:
			if (CurY > 0)
			{ 
			Field[CurY][CurX] = Field[CurY - 1][CurX];
			Field[CurY - 1][CurX] = 0;
			CurY--;
			}
			else {
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		    break;
			}break;
		case down:
			if (CurY < 3)
			{
 			Field[CurY][CurX] = Field[CurY + 1][CurX];
			Field[CurY + 1][CurX] = 0;
			CurY++;
			}
			else {
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		    break;
			}break; 
		case right:
			if (CurX < 3)
			{
		 	Field[CurX][CurX] = Field[CurY][CurX + 1];
			Field[CurY][CurX + 1] = 0;
			CurX++;
			}
			else{
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		    break;
			}break;
		case left:
			if (CurX > 0)
			{
			Field[CurY][CurX] = Field[CurY][CurX - 1];
			Field[CurY][CurX - 1] = 0;
			CurX--;
			} 
			else{
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		    break;
			}break;
	}
}

//ВЫВОД ПОЛЯ
void coutArr(){ 
	system("clear");
	for (u_int i = 0; i < 4; i++) {
		for (u_int j = 0; j < 4; j++) {
			printf("\t%d ",Field[i][j]);
		}
	printf("\n\n");
	}
return;
}  

//Проверка на выигрыш 
bool total() {
u_short k=1;
bool flag = true;
	for (u_short i = 0; i < 4; i++) {
    	for (u_short j = 0; j < 4; i++) {
			if (Field[i][j] != k % 16 )  
				flag = true;
			else {
				flag = false;
				break ;
			}
		k++;	
		}
	}						
		return flag;
}
 
int main(){
CreateField();
coutArr();
printf("Choose a direction 'w,a,s,d'\n");
		while(!total()) {
		char key = getchar();
		 switch (key)
		  {
			case 119:
			  Move(up);
			  coutArr();
			  break;
			case 115:
			  Move(down);
			  coutArr();
			  break;
			case 100:
			  Move(right);
			  coutArr();
			  break;
			case 97:
			  Move(left);
			  coutArr();
			  break;
			case 27:
			  printf("NICE TRY\n"); 
			  return 0;
			  break;
		  }
		}
printf(" ====Congratulations! Press Esc to exit====  ");
return 0;
}
