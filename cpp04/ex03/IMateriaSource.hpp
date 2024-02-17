/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:14:15 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:14:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <string>
# include "AMateria.hpp" 

class IMateriaSource
{
    public:
 
       virtual ~IMateriaSource(void) {};
       virtual void learnMateria(AMateria*) = 0;
       virtual AMateria * createMateria(std::string const & type) = 0;
};
#endif // IMATERIASOURCE_H

