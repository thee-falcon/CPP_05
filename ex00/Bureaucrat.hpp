/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:58:05 by omakran           #+#    #+#             */
/*   Updated: 2024/03/03 19:25:38 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

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

    /* ######################################## Exception Classes: ################################################## */
    // You can define your own exception classes by inheriting from the std::exception class or its derived classes.  //
    // std::exception is a base class for most standard C++ exception types.                                          //
    // std::exception is an abstract class, which means that you cannot create an instance of it directly. Instead,   //
    // you are meant to derive your exception classes from it.                                                        //
    /* ############################################################################################################## */
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too high"; }
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Grade too low"; }
    };

    // member functions:
    std::string getName( void ) const;
    int         getGrade( void ) const;

    void        incrementGrade( void );
    void        decrementGrade( void );
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

//                                                               ========> Reminder <=========
/* #################################################################### std::ostream #################################################################### */
// std::ostream is a class in the C++ Standard Library that represents an output stream.                                                                  //
//                                                                                                                                                        //
// The goal is to define a way to output information about a Bureaucrat object to an output stream (like std::cout).                                      //
// By overloading the << operator, you enable the usage of the stream insertion operator (<<) with Bureaucrat objects.                                    //
// std::ostream& os: This is the left operand, representing the output stream on which the data will be written.                                          //
//                   It is passed by reference to allow modifications to the actual stream.                                                               //
// const Bureaucrat& bureaucrat: This is the right operand, representing the Bureaucrat object whose information is being written to the output stream.   //
//                               It is passed by reference to avoid unnecessary copying of the object.                                                    //
/* ###################################################################################################################################################### */

#endif