#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <cassert>


// void testBureaucrat() {
//     std::cout << "Testing Bureaucrat..." << std::endl;

//     Bureaucrat b1("John", 50);
//     assert(b1.getName() == "John" && b1.getGrade() == 50);

//     b1.increaseGrade();
//     assert(b1.getGrade() == 49);
//     b1.decreaseGrade();
//     assert(b1.getGrade() == 50);

//     try {
//         Bureaucrat b2("Alice", 0);
//     } catch (const Bureaucrat::GradeTooHighException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat b3("Bob", 151);
//     } catch (const Bureaucrat::GradeTooLowException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     std::cout << b1;
// }

// void testForm() {
//     std::cout << "Testing Form..." << std::endl;

//     Form f1("Tax Form", 50, 25);
//     assert(f1.getName() == "Tax Form" && f1.getGradeToSign() == 50 && f1.getGradeToExecute() == 25 && !f1.getIsSigned());

//     try {
//         Form f2("Invalid Form", 0, 25);
//     } catch (const Form::GradeTooHighException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     try {
//         Form f3("Another Invalid Form", 50, 151);
//     } catch (const Form::GradeTooLowException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     Bureaucrat b1("John", 40);
//     Bureaucrat b2("Alice", 60);

//     f1.beSigned(b1);
//     assert(f1.getIsSigned());

//     Form f2("Another Form", 30, 20);
//     b2.signForm(f2);

//     b1.signForm(f2);

//     std::cout << f1;
//     std::cout << f2;
// }

// int main() {
//     testBureaucrat();
//     testForm();

//     std::cout << "All tests passed successfully!" << std::endl;
//     return 0;
// }



// my test
int main()
{
    std::cout << "*** TESTING BUREAUCRAT CLASS ***" << std::endl;

    try
    {
        // Создаем бюрократа с допустимой градацией
        Bureaucrat validBureaucrat("John Doe", 100);
        std::cout << validBureaucrat << std::endl;

        // Пытаемся создать бюрократа с недопустимой высокой градацией
        Bureaucrat invalidHighGradeBureaucrat("Jane Smith", 0);
        std::cout << invalidHighGradeBureaucrat << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Пытаемся создать бюрократа с недопустимой низкой градацией
        Bureaucrat invalidLowGradeBureaucrat("Bob Johnson", 151);
        std::cout << invalidLowGradeBureaucrat << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat validBureaucrat("Alice Williams", 50);
    std::cout << validBureaucrat << std::endl;

    // Увеличиваем градацию бюрократа
    validBureaucrat.increaseGrade();
    std::cout << validBureaucrat << std::endl;

    // Уменьшаем градацию бюрократа
    validBureaucrat.decreaseGrade();
    std::cout << validBureaucrat << std::endl;

    std::cout << std::endl;
    std::cout << "*** TESTING FORM CLASS ***" << std::endl;

    try
    {
        // Создаем форму с допустимыми градациями
        Form validForm("Contract", 50, 40);
        std::cout << validForm << std::endl;

        // Пытаемся создать форму с недопустимой градацией для подписания
        Form invalidSignGradeForm("Agreement", 0, 40);
        std::cout << invalidSignGradeForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Пытаемся создать форму с недопустимой градацией для исполнения
        Form invalidExecuteGradeForm("Proposal", 50, 151);
        std::cout << invalidExecuteGradeForm << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    Form validForm("Contract", 50, 40);
    Bureaucrat lowGradeBureaucrat("John Smith", 60);
    Bureaucrat highGradeBureaucrat("Jane Doe", 40);

    // Бюрократ с низкой градацией пытается подписать форму
    lowGradeBureaucrat.signForm(validForm);
    std::cout << validForm << std::endl;

    // Бюрократ с высокой градацией подписывает форму
    highGradeBureaucrat.signForm(validForm);
    std::cout << validForm << std::endl;

    return 0;
}