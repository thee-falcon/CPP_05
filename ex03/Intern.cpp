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

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
    AForm *obj = NULL;
    int index = 2;  // Initialize to the last index

    std::string s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++){
        if (s[i] == formName) {
            index = i;
            break;  // Exit loop as soon as the formName is found
        }
    }

    switch (index) {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            obj = new ShrubberyCreationForm(target);
            break;
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            obj = new RobotomyRequestForm(target);
            break;
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            obj = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::InternException();
    }
    return obj;
}
