/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:40:21 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/12 20:03:50 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try 
    {
        Bureaucrat b("B", 1);
        Intern i;
        Form *F;

        F = i.makeForm("shrubbery creation", "Bender");
        if (F)
        {
            F->beSigned(b);
            F->execute(b);
        }
    }
    catch (std::exception & e)
    {
        std::cout<< e.what() <<std::endl;
    }
    return 0;
}