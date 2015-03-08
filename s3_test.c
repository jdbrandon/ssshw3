#include <stdlib.h>
#include <stdio.h>

int main ()
{
int nonce = rand();
int y = nonce; // OK

nonce = 5;

int z = nonce; // NOT OK



return 0;
} 
