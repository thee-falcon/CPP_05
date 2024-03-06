/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:18 by omakran           #+#    #+#             */
/*   Updated: 2024/03/06 16:49:50 by omakran          ###   ########.fr       */
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

void    Form::beSigned( Bureaucrat& bureaucrat ) {
    if (bureaucrat.getGrade() <= _gradeRequiredToSign) {
        _isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}