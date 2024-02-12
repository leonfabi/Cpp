/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:42:06 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/12 15:29:39 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
AForm("PresidentialPardonForm", 25, 5, target){
    std::cout << "PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &old_obj){
    if (this != &old_obj){
        AForm::operator=(old_obj);
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old_obj): AForm(old_obj){}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if(this->isExecutable(executor) == true){
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n"
        "Hey there, Mr. President of the whole wide Galaxy – Zaphod Beeblebrox here,\n"
        "yeah, the same one and only. Listen, I know we've had our, let's call them,\n"
        "interstellar misunderstandings. You know how it is, cruising through the\n"
        "cosmos, making waves, shaking up the universe – all in a day's work for a guy\n"
        "with two heads and three arms, right?\n\n"
        "But here's the thing, I've been doing some thinking – which, I assure you, is\n"
        "no small feat given the sheer awesomeness occupying my two brains – and it\n"
        "dawned on me, maybe, just maybe, I might've ruffled some feathers. Or antennae.\n"
        "Or whatever it is you've got going on there.\n\n"
        "I gotta say, upsetting the big kahuna, the head honcho, the top banana of the\n"
        "galaxy – not my brightest moment. I mean, who wants the hassle? Not me, I'm\n"
        "more about the good times, the big laughs, and, of course, the spotlight. But,\n"
        "hey, even a semi-divine being (if I do say so myself) can slip up now and then.\n\n"
        "So, here it is: I'm sorry. Yeah, you heard right. Zaphod Beeblebrox is\n"
        "apologizing. Put it in the headlines, make it known across the stars. I'm\n"
        "manning up – or, well, whatever it is we do in my uniquely exceptional case –\n"
        "and saying I hope we can cruise past this little hiccup on the cosmic highway.\n\n"
        "Let's face it, the galaxy's a wild, wacky place, and it needs characters like\n"
        "us to keep things interesting, am I right? So, what do you say we put this\n"
        "behind us, maybe over a Pan Galactic Gargle Blaster or two? On me, naturally.\n"
        "I know this great little place on Betelgeuse V – the ambiance is just electric.\n\n"
        "Yours in cosmic camaraderie,\n"
        "Zaphod Beeblebrox\n";
    }
}