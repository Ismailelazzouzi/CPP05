#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

class AForm
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
    AForm();
    AForm(const std::string &name, const int signGrade, const int exeGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    const  std::string getName() const;
    int         getSignGrade() const;
    int         getexeGrade() const;
    bool               getState() const;
    void               beSigned(Bureaucrat const &Bureaucrat);
    virtual bool               execute(Bureaucrat const & executor) const = 0;
    ~AForm();
};

std::ostream    &operator<<(std::ostream &out, AForm &obj);
