/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:16:37 by atardif           #+#    #+#             */
/*   Updated: 2023/11/16 15:29:17 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class   Sample{

    private :

        std::string _login;

    public :

        Sample(std::string login) : _login(login){
        }
        ~Sample(void){
        }

        std::string const &getloginconstRef(void){
            return this->_login;
        }
        std::string const *getloginconstPoint(void){
            return &(this->_login);
        }
        std::string &getloginRef(void){
            return this->_login;
        }
        std::string *getloginPoint(void){
            return &(this->_login);
        }
};

int main(void){

    Sample  sample("bclinton");

    std::cout << sample.getloginconstRef() << std::endl;
    std::cout << *(sample.getloginconstPoint()) << std::endl;

    sample.getloginRef() = "bobama";
    std::cout << sample.getloginconstRef() << std::endl;

    *(sample.getloginPoint()) = "emicron";
    std::cout << *(sample.getloginconstPoint()) << std::endl;
    return (0);
}

