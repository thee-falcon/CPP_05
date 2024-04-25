/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:57:59 by omakran           #+#    #+#             */
/*   Updated: 2024/03/08 18:25:57 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void    Bureaucrat::signForm( Form& Form ) {
    try {
        Form.beSigned(*this);
        std::cout << Form.getName() << " signed " << _name << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << Form.getName() << " couldn't sign " << _name << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName();
    os << ", bureaucrat grade "; 
    os << bureaucrat.getGrade();
    return (os);
}
