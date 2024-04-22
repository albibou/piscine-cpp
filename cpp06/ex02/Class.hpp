/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:44:55 by atardif           #+#    #+#             */
/*   Updated: 2024/04/22 15:44:56 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# include <iostream>
# include <cstdlib>

# ifndef PRINT
#  define PRINT 0
# endif

class Base{

  public :

    virtual ~Base(void) {};

  private :

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
