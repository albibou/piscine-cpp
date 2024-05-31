/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:04:32 by atardif           #+#    #+#             */
/*   Updated: 2024/05/31 14:04:33 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <stack>
# include <cstdlib>


# ifndef PRINT
#  define PRINT 0
# endif

# define USAGE "Use with a string argument in Reverse Polish Notation (operators followed by operands)"
# define EXAMPLE "Example : ./RPN \"1 2 + 3 *\" "
# define BAD_CHARACTER_ERROR " Usage of a wrong character"
# define STACK_TOO_SMALL " Trying to operate with less than two operands"
# define OPERATION_OVERFLOW " : this operation will over/underflow int capacity"
# define ZERO_DIVISION " Division by 0 is impossible"
# define REST_OPERAND " Not enough operators"
# define SPACES " Operand and operators must be separated by spaces, numbers must be between 0 and 9"

class RPN{

  public :

    RPN(void);
    RPN(RPN const & rhs);
    ~RPN(void);

    RPN & operator=(RPN const & rhs);

    bool  calculate_RPN(std::string const & litteral);
    std::string  get_error(void) const;

  private :

    std::stack<int> _stack;
    std::stringstream _error;
    bool  _must_be_space;

    bool  is_operand(char const value) ;
    bool  is_operator(char const value) ;
    std::string  get_faulty_operation(char const op, int operand1, int operand2);
    bool  do_operation(char const op);
};

#endif
