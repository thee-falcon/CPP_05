/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:16:01 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 21:35:19 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& name )
    : AForm("Shrubbery Creation Form", 145, 137), _target(name) { 
        
    }

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    }

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // Check if the form is signed
    if (!this->getIsSigned()) {
        throw AForm::NotSignedException();
    }

    // Check if the executor's grade is high enough
    if (executor.getGrade() > this->getExecuteGrade()) {
        throw Form::GradeTooLowException();
    }

    // Create and write to the file
    std::ofstream file(this->getName() + "_shrubbery");
    if (!file.is_open()) {
        std::cerr << "Error opening file for ShrubberyCreationForm: " << _target << std::endl;
        return;
    }

    file << "                      ___" << std::endl;
    file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "             ,-'          __,,-- \\" << std::endl;
    file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << "     (     ,-'                  `." << std::endl;
    file << "      `._,'     _   _             ;" << std::endl;
    file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    file << "                \"Hb HH dF" << std::endl;
    file << "                 \"HbHHdF" << std::endl;
    file << "                  |HHHF" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  |HHH|" << std::endl;
    file << "                  dHHHb" << std::endl;
    file << "                .dFd|bHb.               o" << std::endl;
    file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    file << "##########################################" << std::endl;

    file.close();
}
std::string ShrubberyCreationForm::getTarget() const {
    return (_target);
}