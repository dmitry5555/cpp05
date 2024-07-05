#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;
		void executeForm() const;


	public:
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm(RobotomyRequestForm& obj);	
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
};

#endif