/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:22 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 14:44:59 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void){

    int nb = 9;
    int *pnb = &nb;
    int &refnb = nb;
    
    std::cout << nb << " " << *pnb << " " << refnb << std::endl;

    *pnb = 12;

    std::cout << nb << std::endl;
 
    refnb = 24;

    std::cout << nb << std::endl;
    return (0);
}
