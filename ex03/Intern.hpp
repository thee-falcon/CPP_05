/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:22:15 by omakran           #+#    #+#             */
/*   Updated: 2024/03/15 17:57:35 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

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

    Form* makeForm( std::string &formName, std::string &target) const;
};

#endif