# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aisner <aisner@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 08:12:25 by aisner            #+#    #+#              #
#    Updated: 2021/12/23 13:31:50 by aisner           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name of the target
NAME = GNL 

# Source files

MANDOTORY_FILES  =  get_next_line.c	get_next_line_utils.c main.c
BONUS  =  get_next_line_bonus.c	get_next_line_utils_bonus.c main.c

OBJ = $(MANDOTORY_FILES:.c=.o)  
OBJ2 = $(BONUS:.c=.o)
FLAGS = -c -Wall -Wextra -Werror

INCL = -I./get_next_line.h

INCL_B = -I./get_next_line_bonus.h

FLAGS = -Wall -Wextra -Werror

.c.o:
		@make
		gcc ${FLAGS} -c $< -o ${<:.c=.o}
 

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec. FUCKING MAGIC"
	@gcc -o $(NAME) -D BUFFER_SIZE=42 $(FLAGS) $(MANDOTORY_FILES) $(INCL)   
	@echo "(•̀ᴗ•́)و $(NAME) generated! GOOD JOB".

bonus:
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec. FUCKING MAGIC"
	@gcc -o $(NAME) -D BUFFER_SIZE=42 $(FLAGS) $(BONUS) $(INCL_B)   
	@echo "(•̀ᴗ•́)و $(NAME) bonus generated! GOOD JOB".

all: $(NAME)
	
clean :
	
	@/bin/rm -f $(OBJ)

fclean: 
	@/bin/rm -f $(NAME) get_next_line.h.gch $(OBJ)

re : fclean all

.PHONY: all clean fclean re