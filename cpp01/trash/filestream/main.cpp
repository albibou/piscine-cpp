/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:16 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 15:46:05 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(void){

    std::ifstream   ifs("numbers");
    unsigned int    dst;
    unsigned int    dst2;

    ifs >> dst >> dst2 ;
    std::cout << dst << " " << dst2 << std::endl;

    std::ofstream   ofs("test.out");

    ofs << "I love macaronis" << std::endl;
    ofs.close();
    ifs.close();
    return (0);
}
