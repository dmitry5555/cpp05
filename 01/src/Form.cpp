#include "Form.hpp"

// констр
Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) 
		: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor passed " << std::endl;
}

// копи констр.
Form::Form(const Form& other)
		: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Copy constructor .." << std::endl;
}

// дестр
Form::~Form() {
	std::cout << "Form destructor .." << std::endl;
}

// оператор присваивания. передает зн-я одного объекта в другой
// то есть сначала инициализирует новый и потом передает значения из текущего
Form& Form::operator=(const Form& other) {
	if (this == &other)
		return *this;
	_isSigned = other._isSigned;
	// остальные константы и не могут быть изменены
	return *this;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

// метод beSigned для подписания формы
void Form::beSigned(Bureaucrat& bureaucrat) {
	if (_gradeToSign < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "⚠️ Grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "⚠️ Grade is too high";
}

const char* Form::FormAlreadySigned::what() const throw() {
	return "⚠️ Form is already signed";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form " << obj.getName() << " is signed: " << obj.getIsSigned() << ", grade to sign: " << obj.getGradeToSign() << ", grade to execute: " << obj.getGradeToExecute() << std::endl;
	return os;
}