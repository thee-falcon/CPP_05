/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:18 by omakran           #+#    #+#             */
/*   Updated: 2024/03/03 19:50:50 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string& name, int signGrade, int executeGrade) : _name(name), _isSigned(signGrade), _gradeRequiredToExecute(executeGrade) {
    
}

Form::~Form( void ) {
    
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