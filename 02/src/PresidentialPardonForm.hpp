#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
		void executeForm() const;

	public:
		PresidentialPardonForm(const std::string);
		PresidentialPardonForm(PresidentialPardonForm& obj);	
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);	
};

#endif