/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:21 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 23:51:22 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    // Create a bureaucrat
    Bureaucrat bureaucrat("Omar", 50);

    // Create forms
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Bender");
    PresidentialPardonForm presidentialForm("Zaphod");

    try {
        // Attempt to sign forms
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.signForm(robotomyForm);
        bureaucrat.signForm(presidentialForm);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Attempt to execute forms
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(presidentialForm);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}
