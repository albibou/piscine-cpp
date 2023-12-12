/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:27:42 by atardif           #+#    #+#             */
/*   Updated: 2023/12/12 14:27:43 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){

    if (argc != 2)
    {
        std::cout << "Use as ./harl \"complaint\"" << std::endl;
        return (1);
    }

    Harl    harl;
    std::string str(argv[1]);

    harl.complain(str);
    return(0);
}
