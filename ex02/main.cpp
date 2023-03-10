/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:40:21 by fstitou           #+#    #+#             */
/*   Updated: 2023/02/12 19:55:02 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
   try 
   {
        Bureaucrat B("aristo",5);
        ShrubberyCreationForm S("ASCII tree");
        RobotomyRequestForm R("Robot");
        PresidentialPardonForm P("President");
        S.beSigned(B);
        S.execute(B);
        R.beSigned(B);
        R.execute(B);
        P.beSigned(B);
        P.execute(B);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}