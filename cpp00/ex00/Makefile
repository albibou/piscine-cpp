# Project

NAME = Megaphone 

# Compiler

CPP	= c++
FLAGS	= -Wall -Werror -Wextra -std=c++98

# Paths

SRC_PATH	= ./src/
BIN_PATH	= ./bin/

# Includes

INCLUDES	= includes/

# Clean

RM	= rm -rf

# Files

SRC	= megaphone.cpp \

OBJ	= $(addprefix $(BIN_PATH), $(SRC:.c=.o))

DEPS		= $(OBJ:.o=.d)

.c.o :	
		${CPP} ${FLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

$(BIN_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(dir $@)
		@ $(CPP) $(FLAGS) -c $< -o $@

${NAME} :	${OBJ}
		${CPP} -o ${NAME} -g ${FLAGS} ${OBJ} 
		clear
	        @toilet -f pagga.tlf --gay "Enjoy ${NAME} !"
	
all :		${NAME}

clean :
		${RM} ${OBJS}

fclean :	clean
		${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re

-include ${DEPS}
