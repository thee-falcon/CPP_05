/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:02 by omakran           #+#    #+#             */
/*   Updated: 2024/03/09 23:14:56 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructor:
AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _gradeRequiredToSign(signGrade), _gradeRequiredToExecute(executeGrade), _isSign(false) {
    checkGrade(_gradeRequiredToSign);
    checkGrade(_gradeRequiredToExecute);
}

// Destructor:
AForm::~AForm() {
}

// Copy Constructor:
AForm::AForm(const AForm& other)
    : _name(other._name),
      _gradeRequiredToSign(other._gradeRequiredToSign),
      _gradeRequiredToExecute(other._gradeRequiredToExecute),
      _isSign(other._isSign) {
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
void Form::checkGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
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
    if (bureaucrat.getGrade() <= _gradeRequiredToSign) {
        _isSign = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
       << ", Execute Grade: " << form.getExecuteGrade() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}
