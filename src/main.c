#include <stdio.h>
#include "IntVector.h"

int main()
{
    IntVector *v;
    v = int_vector_new(10);
    int i;
    printf("cap = %ld\nsize = %ld\n", int_vector_get_capacity(v), int_vector_get_size(v));
    for (i = 0; i < 10; i++)
        int_vector_push_back(v, i);

    for (i = 0; i < 10; i++) {
        printf("%d \n", int_vector_get_item(v, i));
    }

    printf("cap = %ld\nsize = %ld\n", int_vector_get_capacity(v), int_vector_get_size(v));

    for (i = 0; i < 5; i++) {
        int_vector_pop_back(v);
    }
    for (i = 0; i < 5; i++) {
        printf("%d \n", int_vector_get_item(v, i));
    }
    printf("cap = %ld\nsize = %ld\n", int_vector_get_capacity(v), int_vector_get_size(v));
    //
    IntVector *v2 = int_vector_copy(v);
    for (i = 0; i < 5; i++) {
        printf("%d \n", int_vector_get_item(v2, i));
    }
    printf("cap = %ld\nsize = %ld\n", int_vector_get_capacity(v2), int_vector_get_size(v2));
    //
    int_vector_shrink_to_fit(v);
    printf("cap = %ld\nsize = %ld\n", int_vector_get_capacity(v), int_vector_get_size(v));
    int_vector_free(v);
    return 0;
}
