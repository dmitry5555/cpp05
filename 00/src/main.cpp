#include "Bureaucrat.hpp"
#include <iostream>
#include <cassert>

// void testConstructor() {
//     std::cout << "Testing constructor..." << std::endl;

//     // Валидные случаи
//     Bureaucrat b1("John", 1);
//     assert(b1.getName() == "John" && b1.getGrade() == 1);
    
//     Bureaucrat b2("Alice", 150);
//     assert(b2.getName() == "Alice" && b2.getGrade() == 150);

//     // Исключения
//     try {
//         Bureaucrat b3("Bob", 0);
//         assert(false); // Этот код не должен выполниться
//     } catch (const Bureaucrat::GradeTooHighException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat b4("Charlie", 151);
//         assert(false); // Этот код не должен выполниться
//     } catch (const Bureaucrat::GradeTooLowException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }
// }

// void testGradeMethods() {
//     std::cout << "Testing grade methods..." << std::endl;

//     Bureaucrat b("Test", 75);

//     // Увеличение грейда
//     b.increaseGrade();
//     assert(b.getGrade() == 74);

//     // Уменьшение грейда
//     b.decreaseGrade();
//     assert(b.getGrade() == 75);

//     // Исключение при слишком высоком грейде
//     Bureaucrat highGrade("High", 1);
//     try {
//         highGrade.increaseGrade();
//         assert(false); // Этот код не должен выполниться
//     } catch (const Bureaucrat::GradeTooHighException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     // Исключение при слишком низком грейде
//     Bureaucrat lowGrade("Low", 150);
//     try {
//         lowGrade.decreaseGrade();
//         assert(false); // Этот код не должен выполниться
//     } catch (const Bureaucrat::GradeTooLowException& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }
// }

// void testOutputOperator() {
//     std::cout << "Testing output operator..." << std::endl;

//     Bureaucrat b("OutputTest", 42);
//     std::cout << b;
//     // Проверьте вручную, что вывод соответствует формату: "OutputTest, bureaucrat grade 42"
// }

// int main() {
//     testConstructor();
//     testGradeMethods();
//     testOutputOperator();

//     std::cout << "All tests passed successfully!" << std::endl;
//     return 0;
// }

// my tests
int main() {
	
    try {
        Bureaucrat bureaucrat1("Alice", 150); // Создание бюрократа с уровнем грейда 150
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "GradeTooHighException caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat2("Bob", 0); // Создание бюрократа с уровнем грейда 0
    // } catch (const Bureaucrat::GradeTooLowException &e) {
    //     std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat3("Charlie", 5);
        std::cout << bureaucrat3 << std::endl; // Вывод информации о бюрократе

        bureaucrat3.decreaseGrade(); // Попытка уменьшить уровень грейда ниже минимально допустимого
        std::cout << bureaucrat3 << std::endl;
    // } catch (const Bureaucrat::GradeTooLowException &e) {
    //     std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return 0;
}
