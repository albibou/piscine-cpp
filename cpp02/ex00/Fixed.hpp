/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:19:04 by atardif           #+#    #+#             */
/*   Updated: 2023/12/15 11:19:05 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
 
#include <iostream>

class Fixed
{
   public:
 
      Fixed(void);
      Fixed(Fixed const & src);
      ~Fixed(void);
 
      Fixed &  operator=(Fixed const & rhs);

      int   getRawBits(void) const;
      void  setrawBits(int const raw);
 
   private:

      int   _rawBits;
      static const int  _fractBits = 8;
};
#endif // FIXED_H

