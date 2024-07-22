#ifndef AFORM_HPP
#define AFORM_HPP

// #include <cstdlib>
// #include <ctime>
#include <fstream>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	protected:
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		virtual void	executeForm() const = 0;
		// 0 - ее нет в базовом классе но должен определить в наследнике
		// наследники должны переопределить (реализовать) этот метод


	public:
		virtual ~AForm();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat& bureaucrat);
		void isSigned() const;
		
		void execute(const Bureaucrat& executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif