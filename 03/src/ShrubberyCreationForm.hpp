#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;
		void executeForm() const;

	public:
		ShrubberyCreationForm(const std::string);
		ShrubberyCreationForm(ShrubberyCreationForm& obj);	
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);	
};

#endif