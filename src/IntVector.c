#include "IntVector.h"
#include <stdlib.h>
#include <string.h>
#define CHECK_VECTOR_NULL if (!v) return NULL;
#define CHECK_VECTOR_NUM if (!v) return -1;

IntVector *int_vector_new(size_t initial_capacity)
{
if (initial_capacity < 0) {
    return NULL;
}
IntVector *v = malloc(sizeof(IntVector));
CHECK_VECTOR_NULL
v->vector = malloc(initial_capacity * sizeof(int));
if (!v->vector) {
free(v);
return NULL;
}
v->capacity = initial_capacity;
v->size = 0;
return v;
}

IntVector *int_vector_copy(const IntVector *v)
{
CHECK_VECTOR_NULL
IntVector *vec = malloc(sizeof(IntVector));
if (!vec) 
return NULL;
vec->capacity = v->capacity;
vec->size = v->size;
vec->vector = malloc(vec->capacity * sizeof(int));
vec->vector = memcpy(vec->vector, v->vector, vec->capacity * sizeof(int));
return vec;
}

void int_vector_free(IntVector *v)
{
if (v){
free(v->vector);
free(v);
}
}

int int_vector_get_item(const IntVector *v, size_t index)
{
CHECK_VECTOR_NUM
    if (index >= v->size)
        return -1;
return v->vector[index];
}

void int_vector_set_item(IntVector *v, size_t index, int item)
{
CHECK_VECTOR_NULL
if (index < v->size)
v->vector[index] = item;
}

size_t int_vector_get_size(const IntVector *v)
{
CHECK_VECTOR_NUM
return v->size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
CHECK_VECTOR_NUM
return v->capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
CHECK_VECTOR_NUM
if (v->size == v->capacity) {
        v->capacity *= 2;
        int *new_vec = realloc(v->vector, v->capacity * sizeof(int));
if (!new_vec)
    return -1;
v->vector = new_vec;
    }
    v->vector[v->size] = item;
    v->size++;
    return 0;
}

void int_vector_pop_back(IntVector *v)
{
CHECK_VECTOR_NULL
if (v->size > 0) {
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector *v)
{
CHECK_VECTOR_NUM
if (v->size < v->capacity) {
        v->capacity = v->size;
        int *new_vec = realloc(v->vector, v->capacity * sizeof(int));
if (!new_vec)
    return -1;
v->vector = new_vec;
    }
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size)
{
CHECK_VECTOR_NUM
if (new_size < 0) {
return -1;
}
if (new_size > v->size) {
if (new_size > v->capacity) {
v->capacity = new_size;
            int *new_vec = realloc(v->vector, v->capacity * sizeof(int));
            if (!new_vec)
                return -1;
            v->vector = new_vec;
}
for (size_t i = v->size; i < new_size; i++) {
v->vector[i] = 0;
        }
}
v->size = new_size;
return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity)
{
if (new_capacity < 0) {
return -1;
}
if (new_capacity > v->capacity) {
        v->capacity = new_capacity;
        int *new_vec = realloc(v->vector, v->capacity * sizeof(int));
if (!new_vec)
    return -1;
v->vector = new_vec;
return 0;
    }
else if (new_capacity < v->size) {
v->size = new_capacity;
int *new_vec = realloc(v->vector, new_capacity * sizeof(int));
        if (!new_vec)
            return -1;
        v->vector = new_vec;
        return 0;
}
}

