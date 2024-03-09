/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:43 by omakran           #+#    #+#             */
/*   Updated: 2024/03/09 23:08:17 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib> // For rand().

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);

    // Check if the executor's grade is high enough to execute the form.
    if (executor.getGrade() > getExecuteGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Drilling noises... ";
    
    // Simulate robotomy success or failure (50% success rate).
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const {
    return (_target);
}
