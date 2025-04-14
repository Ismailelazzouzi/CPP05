#include "Form.hpp"
#include "Bureaucrat.hpp"
int main(void)
{
    Form    newForm;
    Bureaucrat newB;

    try{
        Form newForm1("Form 1", 0, 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    newB.signForm(newForm);
    std::cout << newForm << std::endl;
    try{
        Form newForm1("Form 1", 1, 2);
        newB.signForm(newForm1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}