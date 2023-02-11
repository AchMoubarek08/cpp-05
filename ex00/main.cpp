#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("martinelli", 1);
        Bureaucrat b("leomessi", 99);
        std::cout << b;
        for(int i = 0; i < 50; i++)
            b.decrementGrade();
        std::cout << b;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}