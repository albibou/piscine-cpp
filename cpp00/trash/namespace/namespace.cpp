/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:06:55 by atardif           #+#    #+#             */
/*   Updated: 2023/11/02 18:24:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int gl_var = 1;
int f(void) {return 2;}

namespace   Foo{

    int gl_var = 2;
    int f(void) {return 4;}

}

namespace   Bar{

    int gl_var = 3;
    int f(void) {return 6;}

}

namespace   Boy = Foo;

int main(void){

    printf("gl_var:   %d\n", gl_var);
    printf("f():   %d\n\n", f());

    printf("Foo::gl_var:   %d\n", Foo::gl_var);
    printf("Foo::f():   %d\n\n", Foo::f());

    printf("Bar::gl_var:   %d\n", Bar::gl_var);
    printf("Bar::f():   %d\n\n", Bar::f());

    printf("Boy::gl_var:   %d\n", Boy::gl_var);
    printf("Boy::f():   %d\n\n", Boy::f());

    printf("::gl_var:   %d\n", ::gl_var);
    printf("::f():   %d\n\n", ::f());

    return 0;

}
