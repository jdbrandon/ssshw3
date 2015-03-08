#include <stdlib.h>
#include <stdio.h>

int main ()
{
int nonce2 = rand();

int z = nonce2; // OK

int *p;
p = &nonce2;
*p = 5;

 z = nonce2; // NOT OK


return 0;
} 
