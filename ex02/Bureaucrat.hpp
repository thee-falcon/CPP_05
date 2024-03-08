/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:16 by omakran           #+#    #+#             */
/*   Updated: 2024/03/08 18:25:00 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>  // Include for std::ostream
# include <string>    // Include for std::string
# include "Form.hpp"

// forward declaration:
class Form;

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;

    // Helper function to check if the grade is within valid range.
    void    checkGrade( void );

public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */

    // constructor:
    Bureaucrat( const std::string& name, int grade );
    // destructor:
    ~Bureaucrat( void );
    // copy constructor:
    Bureaucrat( const Bureaucrat& other );
    // assignement operator:
   Bureaucrat& operator=( const Bureaucrat& other );

    // Exceptions:
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };
    
    std::string getName( void ) const;
    int         getGrade( void ) const;

    void        signForm( Form& Form );

    // Increment and decrement Functions: 
    void        incrementGrade( void );
    void        decrementGrade( void );
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif