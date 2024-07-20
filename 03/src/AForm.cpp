#include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) 
		: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Form constructor passed " << std::endl;
}

AForm::AForm(const AForm& other)
		: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Copy constructor .." << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor .." << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	_isSigned = other._isSigned;
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (_gradeToSign < bureaucrat.getGrade())
        throw Bureaucrat::GradeTooLowException();
	else
		_isSigned = true;
}

void AForm::isSigned() const {
	if (!_isSigned)
		throw std::logic_error("Form is not signed.");
}

// void AForm::execute(Bureaucrat const &executor) const {}
void AForm::execute(const Bureaucrat& executor) const {
	try {
		isSigned();
		if (executor.getGrade() < _gradeToExecute)
			throw std::logic_error("Grade too high to execute the form.");
		try {
			executeForm();
		}
		catch (std::exception& e) {
			std::cerr << "Execution error: " << e.what() << std::endl;
		}
		std::cout << executor.getName() << " executed " << _name << std::endl;

	}
	catch (std::exception& e) {
		std::cerr << executor.getName() << " form can't be executed: " << e.what() << std::endl;
	}
}

// void execute(const Bureaucrat& executor) {
// 	if (executor.getGrade() > getGradeToExecute())
// 		throw GradeTooLowException();
// 	if (!getIsSigned())
// 		throw FormNotSignedException();
// 	if (rand() % 2)
// 		std::cout << "<target> has been robotomized successfully" << std::endl;
// 	else
// 		std::cout << "<target> has been robotomized unsuccessfully" << std::endl;
// }

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "⚠️ Grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "⚠️ Grade is too high";
}

const char* Bureaucrat::FormAlreadySigned::what() const throw() {
	return "⚠️ Form is already signed";
}

const char* Bureaucrat::FormNotSigned::what() const throw() {
	return "⚠️ Form is not signed yet";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Form " << obj.getName() << " is signed: " << obj.getIsSigned() << ", grade to sign: " << obj.getGradeToSign() << ", grade to execute: " << obj.getGradeToExecute() << std::endl;
	return os;
}