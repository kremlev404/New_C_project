#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>


const int stack_Size = 10;
const int stack_Empty = -1;
const int stack_Full = 9;

typedef struct Stack{
char Buf[stack_Size];
int top;
}Stack;

void reset(Stack* stack){
	if(stack!=0) stack -> top = -1;
	return;
}

void push(char sym, Stack* stack){
	stack ->Buf[++stack-> top] = sym;
 return;
}
char pop(Stack* stack){
 return stack ->Buf[stack-> top--];
}

char top(Stack* stack){
 return stack ->Buf[stack-> top];
}

bool is_Empty( const Stack* stack ) {
	return (stack ->top== stack_Empty);
}

bool is_Full( const Stack* stack ) {
	return (stack ->top== stack_Full);
}

int main(){
Stack stack;
char line[]="Hello";
int i;
printf("%c", line);
reset(&stack);
while(line[i]!='\0'){
	if(!is_Full(&stack))
		push(line[i++],&stack);
	else i++;
}
if(!is_Empty(&stack))
	printf("%c\n", &stack);
while(!is_Empty(&stack))
	printf("%c\n", &stack);
return 0;
} 









