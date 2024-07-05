#include <iostream>
// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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