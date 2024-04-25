/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:18 by omakran           #+#    #+#             */
/*   Updated: 2024/03/06 17:04:52 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string& name, int signGrade, int executeGrade) : _name(name), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(executeGrade) {
    _isSigned = false;
    checkGrade(_gradeRequiredToExecute, _gradeRequiredToSign);
}

Form::~Form( void ) {}

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

void Form::checkGrade( int grade_sign, int grade_execute ) {
    if (grade_execute < 1 || grade_sign < 1) {
        throw GradeTooHighException();
    }
    if (grade_execute > 150 || grade_sign > 150) {
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
    if (bureaucrat.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    else
        this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form Name: " << form.getName();
    os << "\nForm Sign: ";
    if (form.getIsSigned())
        os << "true";
    else
        os << "false";
    os << "\nForm Sign Grade: " << form.getSignGrade();
    os << "\nForm Execute Grade: " << form.getExecuteGrade();
    return (os);
}