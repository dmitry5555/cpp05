
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (150 < _grade) {	
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "constructor .." << std::endl;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	// const_cast<std::string&>(_name) = other._name;
	// имя не меняется так как оно константное
	_grade = other._grade;
	return *this;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::string Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::increaseGrade() { // 5 -> 4
	_grade--;
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << "grade is increased by 1 ..." << std::endl;
}

void Bureaucrat::decreaseGrade() { // 5 -> 6
	_grade++;
	if (150 < _grade) { 
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "grade is decreased by 1 ..." << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
};
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}
