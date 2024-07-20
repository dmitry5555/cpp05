#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

static AForm* createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

const Intern::FormCreator Intern::formCreators[] = {
    {"shrubbery creation", createShrubberyForm},
    {"robotomy request", createRobotomyForm},
    {"presidential pardon", createPresidentialPardonForm}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    for (int i = 0; i < formCount; ++i) {
        if (formName == formCreators[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i].create(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " form: unknown form type" << std::endl;
    return nullptr;
}