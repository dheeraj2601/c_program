#include <string.h>
#include <stdlib.h>

typedef struct inner_struct {
   char *name;
   int account;
} inner;

typedef struct outer_struct {
   int count;
   char *company;
   inner *my_inner;
} outer;

outer *
initialize_outer (size_t max) {
    outer *out = malloc(sizeof (outer) * max);
    if (out) {
        memset(out, 0, sizeof (outer) * max);
        out->count = 0; // no need assign 0 to 'account' and NULL to 'name' field
        out->company = NULL; // because memset already assigns 0 to it.
    }
    return out;
}

inner *
initialize_inner (size_t max) {
    inner *in = malloc(sizeof (inner) * max);
    if (in) {
        memset(in, 0, sizeof (inner) * max);
        in->account = 0; // no need assign 0 to 'account' and NULL to 'name' field
        in->name = NULL; // because memset already assigns 0 to it.
    }
    return in;
}
