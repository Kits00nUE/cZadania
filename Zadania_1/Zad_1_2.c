#include <stdio.h>
int main()
{
    int grades[2][5]=
            {
                    {2,3,4,5,2},
                    {4,5,5,4,3}
            };
    int iloscLiczb=0;
    int suma;
    for (int i=0;i<2;i++)
    {
        for(int j=0;j<5;j++)
        {
            suma+=grades[i][j];
            iloscLiczb++;
        }
    }
    printf("suma: %i iloscliczb: %i", suma, iloscLiczb);
    double average=(double) suma/iloscLiczb;
    printf("\nsrednia: %f",average);
}