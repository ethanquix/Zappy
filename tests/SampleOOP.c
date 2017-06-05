/*
** SampleOOP.c for Zappy in /home/wyzlic_a/delivery/Zappy/SampleOOP.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 02:42:17 2017 Dimitri Wyzlic
** Last update Mon Jun 05 02:42:17 2017 Dimitri Wyzlic
*/

#include <stdio.h>


// Example of C++ 'Virtual'
// The top-level class.

typedef struct s_MasterClass {
    int (*hello)(struct s_MasterClass *self, char *name);   //<- This is the virtual function which we are gonna override
} t_MasterClass;

// A class

static int A_Open (t_MasterClass *A, char *name) {
    printf ("Hello, you can see I am the A class: %s\n", name);
    return 0;
}
static int A_Init (t_MasterClass *A) {
    A->hello = &A_Open;
    return 0;
}

// B class

static int B_Open (t_MasterClass *B, char *name) {
    printf ("Hello, you can see I am the B class: %s\n", name);
    return 0;
}
static int B_Init (t_MasterClass *B) {
    B->hello = &B_Open;
    return 0;
}


// Test:
int main()
{
    int status;
    t_MasterClass A, B;

    // Same 'base' class but initialised to different sub-classes.

    A_Init(&A);
    B_Init(&B);

    // Called in exactly the same manner.

    status = (A.hello)(&A, "A");
    status = (B.hello)(&B, "B");

    return 0;
}