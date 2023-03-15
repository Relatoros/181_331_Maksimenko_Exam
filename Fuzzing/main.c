#include <stdlib.h>
#include <stdio.h>


size_t len(const char* s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}

int* generateRand(size_t size)
{

    int* mass = (int*)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i)
        mass[i] = rand() % 10;
    return mass;

}

void show(size_t size, int* mass)
{
    for (int i = 0; i < size; i++)
        printf("%d ", mass[i]);

    printf("\n");

}


void PSort(size_t size, int* mass)
{
    int tmp, noSwap;

    for (int i = size - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }


}


void ISort(size_t size, int* mass)
{
    int newElement, location;

    for (int i = 1; i < size; i++)
    {
        newElement = mass[i];
        location = i - 1;

        while (location >= 0 && mass[location] > newElement)
        {
            mass[location + 1] = mass[location];
            location = location - 1;
        }

        mass[location + 1] = newElement;
    }

}




#define TEST
#ifdef TEST

int LLVMFuzzerTestOneInput(const char* Data, size_t Size)
{

    int s = len(Data);
    PSort(s, Data);
    ISort(s, Data);

    return 0;
}

#else // Not Test
#pragma warning(disable : 4996)

int main()
{
    int* a = generateRand(10);
    int* b = generateRand(8);

    printf("Generate array a:\n");
    show(10, a);
    printf("Generate array b:\n");
    show(8, b);


    printf("Sorted array a:\n");
    PSort(10, a);
    show(10, a);

    printf("Sorted array b:\n");
    ISort(8, b);
    show(8, b);


    free(a);
    free(b);
    return 0;
}
#endif


