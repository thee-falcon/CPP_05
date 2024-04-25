/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:28 by omakran           #+#    #+#             */
/*   Updated: 2024/03/07 16:44:57 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    try {
        std::cout << "#################################\n" << std::endl;

        // Testing Bureaucrat
        Bureaucrat bureaucrat("John Doe", 50);
        std::cout << "Initial Bureaucrat:\n" << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << "After incrementing grade:\n" << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << "After decrementing grade:\n" << bureaucrat << std::endl;
        
        std::cout << "\n#################################" << std::endl;

        // Testing Form
        Form form("Tax Form", 75, 60);
        std::cout << "\nInitial Form:\n" << form << std::endl;

        std::cout << "\n=================================\n" << std::endl;

        bureaucrat.signForm(form);
        std::cout << "After bureaucrat signing the form:\n" << form << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}