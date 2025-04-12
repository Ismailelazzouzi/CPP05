#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    std::string name;
    int grade;
    void    gradeCheck(int grade);
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
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    const std::string getName() const;
    int getGrade() const;
    void    increment();
    void    decrement();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);
