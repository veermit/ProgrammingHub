#include <stdio.h>
#include <stdlib.h>

void cutommalloc(int size, void **ptr)
{
    void *temp = malloc (size);
    if( !temp )
    {
        perror("error allocation");
        return;
    }
    printf("address allocated %p\n", temp);
    *ptr = temp;
    return;
}
int main()
{
    int *ptr;
    cutommalloc(5 * sizeof(int), (void *)&ptr);
    printf("address custom allocated %p\n", ptr);

    return 0;
}
