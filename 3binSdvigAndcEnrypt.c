#include<stdio.h> 
#include<math.h>
typedef unsigned int u_int;
typedef unsigned short u_short;

u_short CountBinar(u_int a) 
{
	u_short counter = 0;
	while (a > 0) 
	{
		counter ++;
		a /= 2;
	}
	return counter;
}

void printAsBinar(u_int a) 
{
int i;
	for (int i = sizeof(u_int) * 8 - 1; i >= 0; i--) 
	{
		u_int mask = (1 << i);
		if (a & mask)
			printf("1");
			
		else
			printf("0");
		
	}
	printf("\n");
}

u_int encryptionBinar(u_int a) {
	u_int res = 0;
    for (u_int mask_1 = 1, mask_st = 2;mask_1 != 0;mask_1 <<= 2, mask_st <<= 2)
    {
    res |= ((a & mask_1) << 1) | ((a & mask_st) >> 1);
    }
 return res;
}

u_int shiftRBinar(u_int a, int shift) 
{
	u_int buf;
 	int i;
	for (i = 0; i < shift; i++) 
	{
		buf = (a%2) << (sizeof(u_int) * 8 - 1);
		a >>= 1;
		a |= buf;
	}
	return a;
}

int main() 
{
	u_int a;
	printf("Enter your digit :");
	scanf("%u", &a);
	printAsBinar(a);
	u_int b = encryptionBinar(a);
	printf("================================\n");
	printAsBinar(b);
	printf("================================\n");                       
	int n;
	printf("Enter shift to the right side : ");
	scanf("%d", &n);
	b = shiftRBinar(a, n);
	printAsBinar(b);
	
return 0; 
}
