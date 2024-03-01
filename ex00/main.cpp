/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:58:03 by omakran           #+#    #+#             */
/*   Updated: 2024/03/01 15:42:59 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John Doe", 50);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;

        // Uncomment the line below to test exception handling
        // Bureaucrat invalidBureaucrat("Invalid", 160);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}