#include "Bureaucrat.hpp"

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


// int main() {
//     try {
// 		Bureaucrat bureaucrat("Alice", 150); // Ошибка: создаем слишком высокий грейд
// 	} catch (Bureaucrat::GradeTooLowException& e) { // Обратите внимание на const перед Bureaucrat::GradeTooHighException
// 		std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
// 	}

//     try {
//         Bureaucrat bureaucrat("Bob", 0); // Ошибка: создаем слишком низкий грейд
//     } catch (Bureaucrat::GradeTooHighException& e) {
//         std::cerr << "GradeTooHighException caught: " << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat bureaucrat("Charlie", 5);
//         std::cout << bureaucrat << std::endl;
      
//         bureaucrat.decreaseGrade(); // Ошибка: уменьшаем уровень грейда до недопустимого значения
//         std::cout << bureaucrat << std::endl;
//     } catch (Bureaucrat::GradeTooLowException& e) {
//         std::cerr << "GradeTooLowException caught: " << e.what() << std::endl;
//     }

//     return 0;
// }