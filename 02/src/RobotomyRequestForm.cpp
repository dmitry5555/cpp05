#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj)
	: AForm(obj), _target(obj._target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}

void RobotomyRequestForm::executeForm() const {
	//Informs that <target> has been pardoned by Zaphod Beeblebrox.
	std::cout << "<target> has been pardoned by Zaphod Beeblebrox" << std::endl;
}
