/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:12 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 23:50:43 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// constructor:
Bureaucrat::Bureaucrat( const std::string& name, int grade ) : _name(name), _grade(grade) {
    checkGrade();
}

// destructor:
Bureaucrat::~Bureaucrat( void ) {}

// copy constructor:
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// assignement operator:
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other.getGrade();
        checkGrade();  // This line to ensure the grade is valid after assignment.
    }
    return (*this);
}

// ############ Increment and decrement Functions: #####################
void Bureaucrat::incrementGrade( void ) {
    if (_grade - 1 >= 1)
        _grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade( void ) {
    if (_grade + 1 <= 150)
        _grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}
// ####################################################################

// Helper Function:
void Bureaucrat::checkGrade( void ) {
    if (_grade < 1) {
        throw GradeTooHighException();
    } else if (_grade > 150) {
        throw GradeTooLowException();
    }
}

std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void    Bureaucrat::signForm( AForm& Form ) {
    try {
        Form.beSigned(*this);
        std::cout << Form.getName() << " signed " << _name << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << Form.getName() << " couldn't sign " << _name << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    if (_grade > form.getSignGrade())
        std::cout << "Bureaucrat is too low\n";
    if (!form.getIsSigned())
        std::cout << "Form not Signed!\n";
    else
        std::cout << _name << " executed " << form.getName() << std::endl;
        form.execute(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (os);
}
