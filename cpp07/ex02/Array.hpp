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

template <typename T> 

class Array{

  public :

    Array(void) : _elements(NULL), _size(0){
      return ;
    }

    Array(unsigned int size) : _size(size) {
      _elements = new T[_size];
      return ;
    }

    Array(Array const & rhs) :  _size(rhs._size){

      if (_size){
        this->_elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
          this->_elements[i] = rhs._elements[i];
      }
      else 
        this->_elements = NULL;
      return ;
    }

    ~Array(void) {
      if (this->_elements)
        delete[] this->_elements;
      return;
    }

    Array<T> & operator=(Array<T> const & rhs){
      if (this != &rhs) {
        this->_size = rhs._size;
        if (this->_elements)
          delete this->_elements;
        if (this->_size){
          this->_elements = new T[_size];
          for (unsigned int i = 0; i < _size; i++)
            this->_elements[i] = rhs._elements[i];
        }
        else 
          this->_elements = NULL;
      }
      return *this;
    }

    T & operator[](unsigned int index) const {
      if (index >= this->_size)
        throw Array<T>::IndexTooBig();
      return this->_elements[index] ;
    }

    unsigned int  size(void)const {
      return (this->_size);
    }

    class IndexTooBig : public std::exception {

      public :
        const char * what() const throw(){
          return ("This index is out of range");
        }
    };

  private :

    T*  _elements;
    unsigned int _size;

};

#endif
