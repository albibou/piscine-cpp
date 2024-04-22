/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:45:42 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:45:43 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <string>
# include <stdlib.h>
# include "Array.tpp"

# ifndef PRINT
#  define PRINT 0
# endif

template <typename T> 

class Array{

  public :

    Array(void);
    Array(unsigned int size);
    Array(Array const & rhs);
    ~Array(void);

    Array<T> & operator=(Array<T> const & rhs);
    T & operator[](unsigned int index) const;


    unsigned int  size(void)const;

    class IndexTooBig : public std::exception {

      public :
        const char * what() const throw();
    };

  private :

    T*  _elements;
    const unsigned int _size;

};


#endif
