#include <stddef.h>
typedef struct
{
size_t capacity;
size_t size;
int *vector;
} IntVector;

IntVector *int_vector_new(size_t capacity);
IntVector *int_vector_copy(const IntVector *v);
void int_vector_free(IntVector *int_vector);
int int_vector_get_item(const IntVector *int_vector, size_t index);
void int_vector_set_item(IntVector *v, size_t index, int item);
size_t int_vector_get_size(const IntVector *v);
size_t int_vector_get_capacity(const IntVector *v);
int int_vector_push_back(IntVector *v, int item);
void int_vector_pop_back(IntVector *v);
int int_vector_shrink_to_fit(IntVector *v);
int int_vector_resize(IntVector *v, size_t new_size);
