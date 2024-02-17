/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:14:51 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/17 11:26:58 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
AForm("ShrubberyCreationForm", 145, 137, target){
    std::cout << "ShrubberyCreationForm Constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old_obj){
    if (this != &old_obj){
        AForm::operator=(old_obj);
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old_obj): AForm(old_obj){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (this->isExecutable(executor) == true){
        const std::string filename = this->getTarget()+"_shrubbery";
        std::ofstream OutFile(filename.c_str());
        OutFile <<
        "                      .-++++=: \n"
        "                    .:++++++++++:. \n"
        "                  :+++++++++++++++:. \n"
        "              .:==++++++++++++++++++ \n"
        "      ..=**+++++++++++++++++++++++++-....... \n"
        "     .:+***++++++++++++++++++++++++++++++++=. \n"
        "    ..-******++++++++++++++++++++++++++++++++. \n"
        "  ..:********++++++++++++++++++++++++++++++++=. \n"
        ".:+********+++++++++++++++++++++++++++++++++++- \n"
        ":+*********+++++++++++++++++++++++++++++++++++- \n"
        "-***************+++++++++++++++++++++++++++++-. \n"
        ".=**************+++++*++++++++++++++++++++=:. \n"
        " .:=********************+++++************=.. \n"
        "   .=******+************************++=-:. \n"
        "    ..:.....-**********************+. \n"
        "            ....:+******#*******=:.. \n"
        "                 .:--:=###:.::... \n"
        "                     .=###:. \n"
        "                     .=###-. \n"
        "                     .+###=. \n"
        "                     :*###*. \n"
        "                    .:#####. \n"
        "                    .-#####: \n"
        "                    .=#####- \n"
        "                    .+#####= \n";
        OutFile.close();
    }
}