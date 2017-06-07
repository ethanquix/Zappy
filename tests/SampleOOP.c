/*
** SampleOOP.c for Zappy in /home/wyzlic_a/delivery/Zappy/SampleOOP.c
**
** Made by Dimitri Wyzlic
** Login   <dimitri1.wyzlic@epitech.eu>
**
** Started on  Mon Jun 05 02:42:17 2017 Dimitri Wyzlic
** Last update Mon Jun 05 02:42:17 2017 Dimitri Wyzlic
*/

#include "Alfred.h"
#include <stdio.h>


// Example of C++ 'Virtual'
// The top-level class.

typedef struct s_MasterClass {
//    ALFRED_MF(int, hello, struct s_MasterClass *this, char *name); <-- macro to help making member function but IDE dont like
    int (*hello)(struct s_MasterClass *this, char *name);   //<- This is the virtual function which we are gonna override
  int (*yop)(struct s_MasterClass *this, void *a);
    int t;
} t_MasterClass;

// A class

static int A_Open (t_MasterClass *this, char *name) {
    printf ("Hello, you can see I am the --A-- class: %s\n", name);
    return 0;
}

static int A_yop(t_MasterClass *this, char *c)
{
  printf("A_yop: %s\n", c);
  return (4);
}

static int A_Init (t_MasterClass *this) {
    this->hello = &A_Open;
  this->yop = (int (*)(struct s_MasterClass *, void *)) &A_yop;
    this->t = 0;
    return 0;
}

// B class

static int B_Open (t_MasterClass *this, char *name) {
    printf ("Hello, you can see I am the --B-- class: %s\n", name);
    return 0;
}

static int B_yop(t_MasterClass *this, int *i)
{
  printf("B_yop: %d\n", *i);
  return (4);
}

static int B_Init (t_MasterClass *this) {
    this->hello = &B_Open;
  this->yop = (int (*)(struct s_MasterClass *, void *)) &B_yop;
    return 0;
}


// Test:
int main()
{
    int status;
    t_MasterClass A, B, C;

    // Same 'base' class but initialised to different sub-classes.

    A_Init(&A);
    B_Init(&B);

    A_Init(&C);

    printf("%d\n", A.t);

    C.t = 40;

    printf("%d\n", A.t);
    printf("%d\n", C.t);
    // Called in exactly the same manner.

    status = (A.hello)(&A, "A");
    status = (B.hello(&B, "B"));

  A.yop(&A, "salut");
  B.yop(&B, &C.t);
//    status = (B.hello)(&B, "B"); <-- same but this one is easier to understand

    return 0;
}