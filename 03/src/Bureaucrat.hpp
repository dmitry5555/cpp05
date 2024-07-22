#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		
		Bureaucrat();

	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other); 

		Bureaucrat& operator=(const Bureaucrat& other);
		
		int getGrade() const;
		std::string getName() const;

		void increaseGrade();
		void decreaseGrade();

		void signForm(AForm& form);
		void executeForm(AForm const & form);
		// void executeForm(const AForm& form)
		// в данном контексте одинаковое поведение

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
