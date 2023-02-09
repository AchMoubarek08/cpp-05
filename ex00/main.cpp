#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("leomessi", 101);
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