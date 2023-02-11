#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form F("formula", 1, 1);
                std::cout << F;
        Bureaucrat B("aristo", 1);
        B.signForm(F);
        // F.beSigned(B);
        std::cout << F;
        // std::cout << F;
        std::cout << B;
        // F.beSigned(B);
        // std::cout << F;          
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}