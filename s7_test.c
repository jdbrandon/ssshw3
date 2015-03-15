#include <stdlib.h>
#include <stdio.h>

int main ()
{

int nonce = rand();
int y = nonce; // OK

nonce = 5;

int z = nonce; // NOT OK

///////////////////////

int nonce_1 = rand();
int y_1 = nonce_1; // OK

nonce_1 = 5;

int z_1 = nonce; // NOT OK

///////////////////////

int nonce2 = rand();

int z1 = nonce2; // OK

int *p;
p = &nonce2;
*p = 5;

 z1 = nonce2; // NOT OK

//////////////////////////

int nonce2_1 = rand();

int z1_1 = nonce2_1; // OK

int *p_1;
p_1 = &nonce2_1;
*p_1 = 5;

 z1_1 = nonce2_1; // NOT OK


return 0;
} 