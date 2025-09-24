#include <iostream>
#include <cctype>
int main(int ac, char **av)
{
    int i = 1;
    int j;

    if (ac < 2)
    {
        std :: cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
        return 1;
    }
    while(av[i])
    {
        j = 0;
        while(av[i][j])
        {
            std :: cout << (char)toupper(av[i][j]);
            j++;
        }
        i++;
    }
    std :: cout << "\n";
    return 0;
}
