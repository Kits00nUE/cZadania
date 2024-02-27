#include <stdio.h>


int main()
{
    for (int i = 0; i < 200; i++)
        if (i % 5 == 0&&i%7==0)
        {
            printf("%s\n", "FooBar");
        }
        else if (i % 5 == 0)
        {
            printf("%s\n", "Foo");
        }
        else if (i % 7 == 0)
        {
            printf("%s\n", "Bar");
        }
        else
        {
            printf("%i\n", i);
        }


    return 0;
}
