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
 
class IMateriaSource
{
    public:
 
       IMateriaSource(void);
       IMateriaSource(IMateriaSource const & src);
       ~IMateriaSource(void);
 
       IMateriaSource &  operator=(IMateriaSource const & rhs);
 
   protected:
 
   private:
 
};
#endif // IMATERIASOURCE_H

