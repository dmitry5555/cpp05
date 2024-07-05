#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& obj)
	: AForm(obj), _target(obj._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}

void ShrubberyCreationForm::executeForm() const {
	// if (!isSigned)
    //     throw Bureaucrat::FormNotSigned();
    // else if (executor.getGrade() > this->getGradeToExecute())
    //     throw Form::GradeTooLowException();
    // run the tree in ASCII
    std::ofstream myFile(_target + "_shrubbery");
    myFile <<"                    ,@@@@@@@," << std::endl;
    myFile <<"       ,,,.   ,@@@@@@@@,  .oo8888o." << std::endl;
    myFile <<"    ,&%%&%&&%,@@@@@@@@@@@,8888888o" << std::endl;
    myFile <<"   ,%&\%&&%&&%,@@@@@@/@@@888888888'" << std::endl;
    myFile <<"   %&&%&%&/%&&%@@@@/ /@@@8888888888'" << std::endl;
    myFile <<"   %&&%/ %&%%&&@@ V /@@' `888 `/88'" << std::endl;
    myFile <<"   `&% ` /%&'    |.|         '|8'" << std::endl;
    myFile <<"       |o|        | |         | |" << std::endl;
    myFile <<"       |.|        | |         | |" << std::endl;
    myFile <<" jgs \\/ ._//_/__/  ,_//__\\/.  _//__/_" << std::endl;
    myFile.close();
}
