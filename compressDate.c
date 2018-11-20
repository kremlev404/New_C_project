#include <stdio.h> ﻿
#include <math.h> ﻿
typedef unsigned short datec_t;
typedef enum Month {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG,
	SEP, OCT, NOV, DEC, MONTHS = 12} Month;

typedef struct Date
{
	int dd;
	Month mm;
	int yy;
} Date;

datec_t compressDate(Date d) {
	datec_t res;
	res=d.yy;
	res += d.dd * pow(2, 7);
	res += d.mm * pow(2, 12);
	return res;
}

Date uncompressDate(datec_t dc) { 
 Date res; 
	res.yy = dc % (datec_t) pow(2, 7); 
	dc /= (datec_t) pow(2, 7); 
	res.dd = dc % (datec_t) pow(2, 5); 
	dc /= (datec_t) pow(2, 5); 
	res.mm = (Month) dc; 
	return res; 
}

datec_t setDay(datec_t dc, int newDay) {
	Date d = uncompressDate(dc);
	d.dd = newDay;
	return compressDate(d);
}

datec_t setMonth(datec_t dc, Month newMonth) {
	Date d = uncompressDate(dc);
	d.mm = newMonth;
	return compressDate(d);
}

datec_t setYear(datec_t dc, int newYear) {
	Date d = uncompressDate(dc);
	d.yy = newYear;
	return compressDate(d);
}

void printDate(Date d) {
	printf("Date : %u.%u.%u\n", d.dd, d.mm, d.yy);
}

void printCompressedDate(datec_t d) {
	printf("Compressed date : %u\n", d);
}

int main() {
Date date;
datec_t datec;
// Ввод первоначальной даты 
printf("Enter first day : ");
scanf("%u", &date.dd);
printf("Enter first mounth : ");
scanf("%u", &date.mm);
printf("Enter first  year : ");
scanf("%u", &date.yy);
datec = compressDate(date); 
printDate(date);
printCompressedDate(datec);
printf("=======================\n");
//////////////////////////  
printf("Enter new day : ");
scanf("%u", &date.dd);
datec = setDay(datec, date.dd);
date = uncompressDate(datec);
printDate(date);
printCompressedDate(datec);
printf("=======================\n");
//////////////////////////  
printf("Enter new mounth : ");
scanf("%u", &date.mm);
datec = setMonth(datec, date.mm);
date = uncompressDate(datec);
printDate(date);
printCompressedDate(datec);
printf("=======================\n");
//////////////////////////      
printf("Enter new year : ");
scanf("%u", &date.yy);
datec = setYear(datec, date.yy);
date = uncompressDate(datec);
printDate(date);
printCompressedDate(datec);
printf("=======================\n");

return 0;
}
