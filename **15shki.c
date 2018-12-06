#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h> 
#include<malloc.h> 

typedef unsigned short u_short;
typedef unsigned int u_int;
typedef enum Direction {up,down,right,left} Direction;

u_short CurX, CurY;

//Создание игровой площадки 
void CreateField(u_short** received ,u_short _size) {
	u_short  n, i, buf, k = 0; 
	u_short* arr = (u_short*)malloc((_size*_size) * sizeof(u_short));
	bool flag = false ;
	srand(time(NULL)); 
	for (n = 0; n < _size*_size; ) { 
		flag = false;
		buf =  rand() % (_size*_size) + 1 ;
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
	for (n = 0; n < _size; n++) 
		for (i = 0; i < _size; i++) { 
			received[n][i] = arr[k]; 
			k++; 
		} 
	received[(_size-1)][(_size-1)] = 0;
	CurX = _size; CurY = _size;
	free(arr);
return; 
} 

// Организация перемещений
void Move(Direction dir, u_short** received, u_short _size) {
	switch(dir) { 
		case up:
			if (CurY > 0)
			{ 
			received[CurY][CurX] = received[CurY - 1][CurX];
			received[CurY - 1][CurX] = 0;
			CurY--;
			}
			else 
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		   	break;
		case down:
			if (CurY < (_size-1))
			{
 			received[CurY][CurX] = received[CurY + 1][CurX];
			received[CurY + 1][CurX] = 0;
			CurY++;
			}
			else 
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		        break; 
		case right:
			if (CurX < (_size-1))
			{
		 	received[CurY][CurX] = received[CurY][CurX + 1];
			received[CurY][CurX + 1] = 0;
			CurX++;
			}
			else
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		   	break;
		case left:
			if (CurX > 0)
			{
			received[CurY][CurX] = received[CurY][CurX - 1];
			received[CurY][CurX - 1] = 0;
			CurX--;
			} 
			else
			printf("ERROR OUT FROM BEYOND THE PLAYING FIELD \n\n");
		   	break;
	}
}

//ВЫВОД ПОЛЯ
void coutArr(u_short** received, u_short _size){ 
	system("clear");
	for (u_int i = 0; i < _size; i++) {
		for (u_int j = 0; j < _size; j++) {
			printf("\t%d ",received[i][j]);
		}
	printf("\n\n");
	}
return;
}  

//Проверка на выигрыш 
bool total(u_short** received, u_short _size) {
u_short k=1;
bool flag = true;
	for (u_short i = 0; i < _size; i++) {
    	for (u_short j = 0; j < _size; j++) {
			if (received[i][j] != k % (_size*_size)) {
				flag = false;
				break;
			}
		
		k++;	
		}
	}						
		return flag;
}
 
int main(){
u_short _size;
scanf("%hu", &_size); 
u_short** Field= (u_short**)malloc(_size * sizeof(u_short*));
for ( u_short i = 0; i < _size; i++)
	Field[i] = (u_short*)malloc(_size * sizeof(u_short));
CreateField(Field, _size);
coutArr(Field, _size); 
printf("Choose a direction 'w,a,s,d'\n");
		while(!total(Field, _size)) {
		char key = getchar();
		 switch (key)
		  {
			case 119:
			  Move(up,Field, _size);
			  break;
			case 115:
			  Move(down,Field, _size);
			  break;
			case 100:
			  Move(right,Field, _size);
			  break;
			case 97:
			  Move(left,Field, _size);
			  break;
			case 27:
			  printf("NICE TRY\n"); 
			  return 0;
			  break;
		  }
		coutArr(Field, _size);
		}
printf(" ====Congratulations! Press Esc to exit====  ");
for (u_short i = 0; i < _size; i++)
		free(Field[i]);
	free(Field);
return 0;
}
