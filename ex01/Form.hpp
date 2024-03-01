/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:20 by omakran           #+#    #+#             */
/*   Updated: 2024/03/01 17:29:33 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

/* ################################# forward declaration: ##################################
//                                                                                        //
// It's useful in situations where the full definition of the class is not needed,        //
//   but the compiler needs to know that the class exists.                                //
//                                                                                        //
// By forward declaring class Bureaucrat;, you tell the compiler that a class             //
// with the name Bureaucrat will be defined later, allowing you to use it                 //
// as a parameter type or a pointer/reference type.                                       //
// The actual definition of Bureaucrat is provided in another header file: bureaucrat.hpp //
// ###################################################################################### */
class Bureaucrat;

class Form
{
    const std::string   _name;
    bool                _signed;
    const int           _gradeRequiredToSign;
    const int           _gradeRequiredToExecute;
        
public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */
    
    // constructor:
    Form(const std::string& name, int signGrade, int executeGrade);
    // copy constructor:
    Form(const Form& other);
    // assignement operator:
    Form& operator=(const Form& other);
    // destructor:
    ~Form();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getSignGrade() const;
    int         getExecuteGrade() const;

    void        beSigned(const Bureaucrat& bureaucrat);
    void        signForm(const Bureaucrat& bureaucrat);

    // Exceptions:
    class GradeTooHighException : public std::exception {
        public:
        virtual const char* what() const throw() { return "Grade too high"; }
    };

    class GradeTooLowException : public std::exception {
        public:
        virtual const char* what() const throw() { return "Grade too low"; }
    };
    
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif