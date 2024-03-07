/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:20 by omakran           #+#    #+#             */
/*   Updated: 2024/03/06 17:05:29 by omakran          ###   ########.fr       */
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
    bool                _isSigned;
    const int           _gradeRequiredToSign;
    const int           _gradeRequiredToExecute;

    // Helper function to check if the grade is within valid range.
    void    checkGrade( int grade );
        
public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */
    
    // constructor:
    Form( const std::string& name, int signGrade, int executeGrade );
    // copy constructor:
    Form( const Form& other );
    // assignement operator:
    Form& operator=( const Form& other );
    // destructor:
    ~Form( void );

    std::string getName( void ) const;
    bool        getIsSigned( void ) const;
    int         getSignGrade( void ) const;
    int         getExecuteGrade( void ) const;

    void        beSigned( Bureaucrat& bureaucrat );

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

std::ostream& operator<<( std::ostream& os, const Form& form );

#endif