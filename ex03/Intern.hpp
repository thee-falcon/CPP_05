/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:22:15 by omakran           #+#    #+#             */
/*   Updated: 2024/04/23 17:14:41 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

class Intern
{

public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */

    // constructor:
    Intern();
    // destructor:
    ~Intern();
    // copy constructor:
    Intern( const Intern& other );
    // assignment operator:
    Intern& operator=( const Intern& other );

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif