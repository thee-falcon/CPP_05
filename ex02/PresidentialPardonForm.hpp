/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:36 by omakran           #+#    #+#             */
/*   Updated: 2024/03/09 22:37:27 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */

    // constructor:
    PresidentialPardonForm(const std::string& target);
    // copy constructor:
    PresidentialPardonForm(const PresidentialPardonForm& other);
    // assignment operator:
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    // destructor:
    virtual ~PresidentialPardonForm();

    void execute(const Bureaucrat& executor) const override;

    std::string getTarget() const;

private:
    std::string _target;
};

#endif