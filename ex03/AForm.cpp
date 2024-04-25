/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:02 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 23:38:29 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructor:
AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSign(false), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(executeGrade) {
        checkGrade(_gradeRequiredToExecute, _gradeRequiredToSign);
}

// Destructor:
AForm::~AForm() {
}

// Copy Constructor:
AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSign(other._isSign),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute) {
}

// Assignment Operator:
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Copy values of non-const members
        _isSign = other._isSign;
    }
    return (*this);
}

// Member Functions:
void AForm::checkGrade( int grade_sign, int grade_execute ) {
    if (grade_execute < 1 || grade_sign < 1) {
        throw GradeTooHighException();
    }
    if (grade_execute > 150 || grade_sign > 150) {
        throw GradeTooLowException();
    }
}

std::string AForm::getName() const {
    return (_name);
}

bool AForm::getIsSigned() const {
    return (_isSign);
}

int AForm::getSignGrade() const {
    return (_gradeRequiredToSign);
}

int AForm::getExecuteGrade() const {
    return (_gradeRequiredToExecute);
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign)
        throw GradeTooLowException();
    else
        this->_isSign = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_isSign) {
        throw AForm::NotSignedException();
    } else if (executor.getGrade() > _gradeRequiredToExecute) {
        throw AForm::GradeTooLowException();
    }
    std::cout << executor.getName() << " executed " << _name << std::endl;
    // Execute the specific action for each concrete form
    // This function should be overridden in each concrete form class
}

std::ostream& operator<<(std::ostream& os, const AForm& aform) {
    os << "AForm Name: " << aform.getName();
    os << "\nAForm Sign: ";
    os << aform.getIsSigned();
    os << "\nAForm Sign Grade: ";
    os << aform.getSignGrade();
    os << "\nAForm Execute Grade: ";
    
    os << aform.getExecuteGrade();
    return (os);
}
