#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    AForm* unknown = someRandomIntern.makeForm("unknown form", "target");
    if (unknown) {
        delete unknown;
    }

    return 0;
}