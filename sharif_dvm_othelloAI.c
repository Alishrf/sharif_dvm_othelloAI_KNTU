#include <stdio.h>

void showmap(char const *p)
{
    int i;
    for (i = 1; i <= 8; ++i)
    {
        for (; *p != '\0'; ++p)
        {
            printf("%c ", *p);
        }
        printf("\n");
        ++p;
        ++p;
    }
}
int main(int argc, char const *argv[])
{
    char const *p = &argv[1][0];
    showmap(p);
    return 0;
}