/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:16:08 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 21:19:57 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    std::string _target;
public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */

    // constructor:
    ShrubberyCreationForm( const std::string& name);
    // copy constructor:
    ShrubberyCreationForm( const ShrubberyCreationForm& other);
    // assignment operator:
    ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other);
    // destructor:
    ~ShrubberyCreationForm();

    void        execute( const Bureaucrat& executor) const;
    std::string getTarget() const;
};


# endif