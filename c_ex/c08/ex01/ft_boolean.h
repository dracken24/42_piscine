#ifndef __lib_bool__
#define __lib_bool__

#include <unistd.h>

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define EVEN(nbr) ((nbr % 2)  == 0)

typedef int	t_bool;

#endif
