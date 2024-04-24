/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:22:13 by omakran           #+#    #+#             */
/*   Updated: 2024/04/23 17:08:48 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {
    
}

Intern::~Intern () {
    
}

Intern::Intern(const Intern& other) {
    // Suppress unused variable warning
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other; // Unused
    return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {

    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm* forms[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)
    };
    
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        } else {
            delete forms[i];  // Deallocate memory if the form isn't created
        }
    }

    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return nullptr;
}
