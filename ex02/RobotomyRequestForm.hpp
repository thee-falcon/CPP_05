/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:15:55 by omakran           #+#    #+#             */
/*   Updated: 2024/03/13 22:02:54 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"


class RobotomyRequestForm: public AForm
{
    std::string _target;
public:
    /* ####################################
    #          Orthodox Style             #
    # ################################### */
    
    // constructor:
    RobotomyRequestForm( const std::string& target);
    // copy constructor:
    RobotomyRequestForm( const RobotomyRequestForm& other);
    // assignment operator:
    RobotomyRequestForm& operator=( const RobotomyRequestForm& other);
    //destructor:
    ~RobotomyRequestForm();

    void        execute( const Bureaucrat& executor) const;
    std::string getTarget() const;
};

#endif