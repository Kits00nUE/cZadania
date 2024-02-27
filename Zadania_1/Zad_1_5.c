#include <stdio.h>


int main()
{
    int suma=0;
    int liczba=50;
    for (int i=0;i<liczba;i++)
    {
        if (i%3==0&i%5==0)
        {
            suma+=i;
        }
        else if (i%3==0)
        {
            suma+=i;
        }
        else if (i%5==0)
        {
            suma+=i;
        }

    }
    printf("suma: %i", suma);
    return 0;
}
