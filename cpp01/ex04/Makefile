# Project

NAME = sed_is_for_losers  

# Compiler

CXX	= c++
FLAGS	= -Wall -Werror -Wextra -MMD -MP -std=c++98 

# Paths

SRC_PATH	= ./
BIN_PATH	= ./bin/

# Includes

INCLUDES	= includes/

# Clean

RM	= rm -rf

# Files

SRC	= ./main.cpp \

OBJ	= $(addprefix $(BIN_PATH), $(SRC:.cpp=.o))

DEPS		= $(OBJ:.o=.d)

.c.o :	
		${CXX} ${FLAGS} -I ${INCLUDES} -c $< -o ${<:.cpp=.o}

$(BIN_PATH)%.o: $(SRC_PATH)%.cpp
		mkdir -p $(dir $@)
		@ $(CXX) $(FLAGS) -c $< -o $@

${NAME} :	${OBJ}
		${CXX} -o ${NAME} -g ${FLAGS} ${OBJ} 
		clear
	        @toilet -f pagga.tlf --gay "Enjoy ${NAME} !"
	
all :		${NAME}

clean :
		${RM} ${OBJ}

fclean :	clean
		${RM} ${BIN_PATH}
		${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re

-include ${DEPS}
