#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form
{
private:
    std::string name;
    int   signGrade;
    int   exeGrade;
    bool        isSigned;
public:
    class   GradeTooHighException : public std::exception
    {
        public :
        virtual const char* what() const throw();        
    };
    class   GradeTooLowException : public std::exception
    {
        public :
        virtual const char* what() const throw();
    };
    Form();
    Form(const std::string &name, const int signGrade, const int exeGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    const  std::string getName() const;
    int         getSignGrade() const;
    int         getexeGrade() const;
    bool               getState() const;
    void               beSigned(Bureaucrat const &Bureaucrat);
    ~Form();
};

std::ostream    &operator<<(std::ostream &out, Form &obj);
