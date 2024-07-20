#include <iostream>
// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// my tests
int main() {
	try {
		// Создание бюрократов с разными рангами
		Bureaucrat bob("Bob", 2);
		Bureaucrat alice("Alice", 2);
		Bureaucrat carol("Carol", 53);
		Bureaucrat dave("Dave", 22);

		// Создание различных форм
		ShrubberyCreationForm shrubberyForm("Create shrubbery");
		RobotomyRequestForm robotomyForm("Request robotomy");
		PresidentialPardonForm pardonForm("Pardon request");

		// Тестирование функции beSigned
		shrubberyForm.beSigned(bob);
		std::cout << "Тест beSigned: " << shrubberyForm.getIsSigned() << std::endl;

		robotomyForm.beSigned(alice);
		std::cout << "Тест beSigned: " << robotomyForm.getIsSigned() << std::endl;

		pardonForm.beSigned(carol);
		std::cout << "Тест beSigned: " << pardonForm.getIsSigned() << std::endl;

		// Тестирование функции execute
		try {
			shrubberyForm.execute(alice);
			robotomyForm.execute(bob);
			pardonForm.execute(dave);
		} catch (const std::exception& e) {
			std::cerr << "Ошибка при выполнении формы: " << e.what() << std::endl;
		}

		// Дополнительные тесты с различными рангами и формами
		try {
			shrubberyForm.execute(bob);
			robotomyForm.execute(alice);
			pardonForm.execute(carol);
		} catch (const std::exception& e) {
			std::cerr << "Ошибка при выполнении формы: " << e.what() << std::endl;
		}
	}
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return (0);;
}



// claude tests
// int main() {
//     bool allTestsPassed = true;

//     try {
//         Bureaucrat highGrade("HighGrade", 1);
//         Bureaucrat lowGrade("LowGrade", 150);
//         Bureaucrat mediumGrade("MediumGrade", 50);

//         std::cout << "\nTesting ShrubberyCreationForm:" << std::endl;
//         ShrubberyCreationForm shrubbery("home");
//         lowGrade.signForm(shrubbery);  // Должно не удаться
//         highGrade.signForm(shrubbery);  // Должно удаться
//         lowGrade.executeForm(shrubbery);  // Должно не удаться
//         highGrade.executeForm(shrubbery);  // Должно удаться

//         std::cout << "\nTesting RobotomyRequestForm:" << std::endl;
//         RobotomyRequestForm robotomy("Bender");
//         mediumGrade.signForm(robotomy);  // Должно удаться
//         mediumGrade.executeForm(robotomy);  // Должно не удаться
//         highGrade.signForm(robotomy);  // Должно удаться (если не было подписано ранее)
//         highGrade.executeForm(robotomy);  // Должно удаться

//         std::cout << "\nTesting PresidentialPardonForm:" << std::endl;
//         PresidentialPardonForm pardon("Zaphod");
//         mediumGrade.signForm(pardon);  // Должно не удаться
//         highGrade.signForm(pardon);  // Должно удаться
//         mediumGrade.executeForm(pardon);  // Должно не удаться
//         highGrade.executeForm(pardon);  // Должно удаться

//         // Дополнительные тесты
//         std::cout << "\nAdditional tests:" << std::endl;
        
//         // Попытка выполнить неподписанную форму
//         ShrubberyCreationForm unsignedForm("test");
//         highGrade.executeForm(unsignedForm);  // Должно не удаться

//         // Попытка создать бюрократа с недопустимым грейдом
//         try {
//             Bureaucrat invalidHigh("TooHigh", 0);
//             allTestsPassed = false;
//             std::cout << "Failed to catch exception for too high grade" << std::endl;
//         } catch (const Bureaucrat::GradeTooHighException&) {
//             std::cout << "Successfully caught exception for too high grade" << std::endl;
//         }

//         try {
//             Bureaucrat invalidLow("TooLow", 151);
//             allTestsPassed = false;
//             std::cout << "Failed to catch exception for too low grade" << std::endl;
//         } catch (const Bureaucrat::GradeTooLowException&) {
//             std::cout << "Successfully caught exception for too low grade" << std::endl;
//         }

//     } catch (std::exception & e) {
//         std::cerr << "Unexpected exception: " << e.what() << std::endl;
//         allTestsPassed = false;
//     }

//     if (allTestsPassed) {
//         std::cout << "\nAll tests passed successfully!" << std::endl;
//     } else {
//         std::cout << "\nSome tests failed. Please review the output above." << std::endl;
//     }

//     return 0;
// }