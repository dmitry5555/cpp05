#include "RobotomyRequestForm.hpp"
#include <cstdlib>

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
	std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "The robotomy of " << _target << " failed" << std::endl;
    }
}
