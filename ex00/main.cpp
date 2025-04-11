#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat A("A", 0);
    }
    catch (const char *Ex)
    {
        std::cout << Ex << std::endl;
    }
    Bureaucrat B("B", 1);
    std::cout << B << std::endl;
    for (size_t i = 0; i < 50; i++)
    {
        B.decrement();
    }
    std::cout << B << std::endl;
    try {
        for (size_t i = 0; i < 100; i++)
        {
            B.increment();
            // B.decrement();
        }
    }
    catch (const char *Ex)
    {
        std::cout << Ex << std::endl;
    }
}