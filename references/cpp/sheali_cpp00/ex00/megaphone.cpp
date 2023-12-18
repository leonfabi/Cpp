# include <cstdio>
# include <cstring>
# include <iostream>
# include <cctype>


int ft_isalpha(char c)
{
    if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

char ft_toupper(char c)
{
    if (ft_isalpha(c))
    {
        if (c >= 'a' && c <= 'z')
            c -= 32;
    }
    return (c);
}

int main(int argc, char **argv)
{
    size_t i = 0;
    size_t j;

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else
    {
        while (++i < argc)
        {
            j = -1;
            while (argv[i][++j] != '\0')
                argv[i][j] = ft_toupper(argv[i][j]);
            std::cout << argv[i];
            if (i < argc - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}
