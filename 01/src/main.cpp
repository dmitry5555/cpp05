#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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