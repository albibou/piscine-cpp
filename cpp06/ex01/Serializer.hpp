/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:44:37 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:44:38 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <string>
# include <stdint.h>

# ifndef PRINT
#  define PRINT 0
# endif

struct  Data{

  int num;
  std::string str;
};

class Serializer{

  public :

    ~Serializer(void);

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);


  private :

    Serializer(void);
    Serializer(Serializer const & rhs);
    Serializer & operator=(Serializer const & rhs);
};

std::ostream & operator<<(std::ostream & o, Serializer const & rhs);

#endif
