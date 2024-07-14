#include "libft.h"

// Si el nuevo tamaño es 0, libera el bloque de memoria actual y devuelve NULL
// Si no hay un bloque de memoria actual, simplemente asigna memoria para el nuevo tamaño
// Asigna memoria para el nuevo tamaño
// Determina el tamaño mínimo entre el tamaño antiguo y el nuevo tamaño
// Copia los datos del bloque de memoria antiguo al nuevo bloque
// Libera el bloque de memoria antiguo
// Devuelve el puntero al nuevo bloque de memoria

void *ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr;
    size_t min_size;

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
    {
        new_ptr = malloc(new_size);
        if (new_ptr == NULL)
        {
            perror("Error allocating memory");
            exit(1);
        }
        return new_ptr;
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        perror("Error reallocating memory");
        exit(1);
    }

    min_size = old_size < new_size ? old_size : new_size;

    ft_memcpy(new_ptr, ptr, min_size);
    free(ptr);

    return new_ptr;
}