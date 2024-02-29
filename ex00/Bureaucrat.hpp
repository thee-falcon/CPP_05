/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:58:05 by omakran           #+#    #+#             */
/*   Updated: 2024/02/29 18:52:20 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    const std::string   _name;
    int                 _grade;

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

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

    std::string getName( void ) const;
    int getGrade( void ) const;

    void incrementGrade( void );
    void decrementGrade( void );
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif