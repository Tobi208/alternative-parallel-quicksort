#include <stdlib.h>
#include <stdio.h>

#define FAST 0

/* From A. Fog: Example 14.4. */

int foo(int j, int size);

int main(int argc, char **argv)
{
    const int size = 16; 
    const int numiters = 100000000;
    int i,j;
    double list[size];
    for(j = 0; j<numiters; j++)
    {
       i = foo(j,size);
#if FAST
       // this works because a negative int cast to unsinged int will
       // be a much larger int and only needs to be checked against size.
       if ((unsigned int) i >= (unsigned int) size) 
       {
          printf("Error: Index out of range");
       }
#else
       if (i < 0 || i >= size) 
       {
          printf("Error: Index out of range");
       }
#endif
       else {
          list[i] += 1.0;
       }
    }
    return 0;
}

/* Pretend you don't know the definition of this function. */
int foo(int j, int size)
{
	return j%size;
}
