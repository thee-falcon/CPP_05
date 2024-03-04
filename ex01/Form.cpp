/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:18 by omakran           #+#    #+#             */
/*   Updated: 2024/03/04 16:35:16 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string& name, int signGrade, int executeGrade) : _name(name), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(executeGrade) {
    checkGrade(_gradeRequiredToSign);
    checkGrade(_gradeRequiredToExecute);
}

Form::~Form( void ) {
    
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute) {
    // No need to checkGrade here, as the grades are assumed to be valid in the existing Form
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other.getIsSigned();
    }
    return (*this);
}

void Form::checkGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

std::string Form::getName ( void ) const {
    return (_name);
}

bool    Form::getIsSigned( void ) const {
    return (_isSigned);
}

int Form::getSignGrade( void ) const {
    return (_gradeRequiredToSign);
}

int Form::getExecuteGrade( void ) const {
    return (_gradeRequiredToExecute);
}

void    Form::beSigned( const Bureaucrat& bureaucrat ) {
    if (bureaucrat.getGrade() <= _gradeRequiredToSign) {
        this->_isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

void    Form::signForm( const Bureaucrat& bureaucrat ) {
    try {
        beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because " << e.what() << std::endl;
    }
}