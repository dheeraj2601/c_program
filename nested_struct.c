#include <string.h>
#include <stdlib.h>

typedef struct inner_struct {
   char *name;
   int account;
} inner;

struct outer_struct {
   int count;
   char *company;
   inner my_inner;
};

int main(int argc, char *argv[]){
   int i;
   size_t max_out = 20;
   struct outer_struct *my_out = malloc(sizeof (struct outer_struct));
   for (i = 0; i<max_out;i++)
      memset(&my_out[i].my_inner, 0, sizeof(inner));
}
