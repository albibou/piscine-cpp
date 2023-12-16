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
 
class MateriaSource
{
    public:
 
       MateriaSource(void);
       MateriaSource(MateriaSource const & src);
       ~MateriaSource(void);
 
       MateriaSource &  operator=(MateriaSource const & rhs);
 
   protected:
 
   private:
 
};
#endif // MATERIASOURCE_H

