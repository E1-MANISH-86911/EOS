/*2. Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). Compile the program using "gcc" and execute it. No fork(), exec() expected
here.
Compilation commands:
gcc -c circle.c
gcc -c square.c
gcc -c rectangle.c
gcc -c main.c
Linking command:
gcc -o program.out circle.o square.o rectangle.o main.o
Execute command:
./program.out
*/

#include<stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"
int main(){
	float r, s, l, b;
	printf("Enter the radius of circle: ");
	scanf("%f", &r);
	printf("Area of circle = %0.2f sq.cm\n", area_of_circle(r));
	printf("Enter the side of square: ");
	scanf("%f", &s);
	printf("Area of square = %0.2f sq.cm\n", area_of_square(s));
	printf("Enter the length of rectangle: ");
	scanf("%f", &l);
	printf("Enter the bredth of rectangle: ");
	scanf("%f", &b);
	printf("Area of rectangle: %0.2f sq.cm\n", area_of_rectangle(l, b));
	return 0;
}
