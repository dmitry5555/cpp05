#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat& bureaucrat);

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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif