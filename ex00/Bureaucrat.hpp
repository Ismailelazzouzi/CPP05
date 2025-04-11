#include <iostream>
#include <string>

class Bureaucrat
{
private:
    std::string name;
    int grade;
    void    gradeCheck(int grade);
public:
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
