#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat(const std::string name, int grade);
		// конст. класса - инициализирует с вход.зн-ми
		Bureaucrat(const Bureaucrat& other);
		// конст. копиров.  берет ссылку на объект Б. инициализирует новый с теми же зн-ми (без иниц-ии)
		~Bureaucrat();
		// дестр

		//&other неверно - src констатная ссылка на объект B. то есть зн-я объекта могут быть изменены при присваивании
		Bureaucrat& operator=(const Bureaucrat& other);
		// верно - src ссылка на конст. объект. не могут быть изменены внутри опер. присваивания !! исх объект не будет изменен внутри оп присв,
		
		std::string getName() const;
		int getGrade() const;

		void increaseGrade();
		void decreaseGrade();

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public: 
				virtual const char* what() const throw();
		};
		
};
// оператор перегрузки
std::ostream& operator<<(std::ostream& os, const Bureaucrat& ojb);
// ссылка на стрим для каскадного вывода
			// имя релоад оператора
						// ссылка на поток вывода
											// ссылка на объект который выведется
// то есть например внутри ф-ии можно вывести грейд и че-то еще для этого Б


#endif
