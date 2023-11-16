/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:24:34 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 14:35:19 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

int main(void)
{
    Sample  test1("jchirac");
    Sample  *test2 = new Sample("bchirac");
    Sample2  *test3 = new Sample2[42];

    delete[] test3;
    delete test2;
    return (0);
}
