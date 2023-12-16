/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:13:49 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:50 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H
 
#include "AMateria.hpp"
#include <string>
#include <iostream>


class Ice : public AMateria
{
    public:
 
       Ice(void);
       Ice(Ice const & src);
       ~Ice(void);
 
       Ice &  operator=(Ice const & rhs);

       virtual Ice* clone() const;
       virtual void use(ICharacter& target);

 
   protected:
 
   private:
 
};
#endif // ICE_H

