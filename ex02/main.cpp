#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form F("formula", 1, 1);
                std::cout << F;
        Bureaucrat B("aristo", 2);
        B.signForm(F);
        std::cout << F;
        std::cout << B;
        // F.beSigned(B);
        // B.signForm(F);
        // std::cout << F;          
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}