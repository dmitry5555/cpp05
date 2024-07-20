#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    struct FormCreator {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    static const FormCreator formCreators[];
    static const int formCount = 3;
};

#endif
