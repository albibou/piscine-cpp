/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:14:36 by atardif           #+#    #+#             */
/*   Updated: 2023/12/16 18:14:37 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource
{
    public:
 
       MateriaSource(void);
       MateriaSource(MateriaSource const & src);
       virtual ~MateriaSource(void);
 
       MateriaSource &  operator=(MateriaSource const & rhs);

       virtual void learnMateria(AMateria* m);
       virtual AMateria * createMateria(std::string const & type);

   protected:

       
   private:

       AMateria *_materiae[4];
};
#endif // MATERIASOURCE_H

