/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:08 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 21:33:18 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

// abstract class.
class AForm
{
protected:
    const std::string   _name;
    bool                _isSign;
    const int           _gradeRequiredToSign;
    const int           _gradeRequiredToExecute;

    // Helper function to check if the grade is within the valid range.
    void    checkGrade(int grade);
    
public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */

    // constructor.
    AForm(const std::string& name, int signGrade, int executeGrade);
    // copy constructor.
    AForm(const AForm& other);
    // assignement operator:
    AForm& operator=(const AForm& other);
    // destructor.
    virtual ~AForm();

    std::string getName( void ) const;
    bool        getIsSigned( void ) const; 
    int         getSignGrade( void ) const;
    int         getExecuteGrade( void ) const;

    void        beSigned( Bureaucrat& bureaucrat );

    // Execute the form's action
    virtual void execute( const Bureaucrat& executor ) const = 0;

    // Exceptions:
    class GradeTooHighException : public std::exception {
        public:
        virtual const char* what() const throw () { return "Grade too high"; }
    };
    
    class GradeTooLowException : public std::exception {
        public:
        virtual const char* what() const throw () { return "Grade too low"; }
    };
    class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form not signed"; }
    };
};

std::ostream& operator<<( std::ostream& os, const AForm& form);

#endif