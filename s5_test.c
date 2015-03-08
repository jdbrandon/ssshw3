#include <stdio.h>
#include <limits.h>


int main(int argc, char **argv)
{

int a = 100;

assert (a >> 1); //OK
assert (a >> 0); // OK
assert (a >> -1); // NOT OK

int b = -100;
int c = 1;
int d = -1;

int test = a >> c; // OK
int test2 = a >> d; // NOT OK


printf("a >> c = %d\n", a>>c); // OK
printf("a >> d = %d\n", a>>d);  // NOT OK

 int test3 = b >> c; // OK
 int test4 = b >> d; // NOT OK

printf("b >> c = %d\n", b>>c); // OK
printf("b >> d = %d\n", b>>d);  // NOT OK

int x = rand();
int y = rand();
int test5 = x >> y; // Cannot tell

}

