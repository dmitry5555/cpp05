#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& obj)
	: AForm(obj), _target(obj._target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}

void PresidentialPardonForm::executeForm() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
