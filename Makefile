# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 20:11:18 by fserlut           #+#    #+#              #
#    Updated: 2019/05/17 00:09:43 by fserlut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a

NAME_FILE = get_next_line.c

SRC = ./libft/*.c

FILE_O = ./*.o

HEAD_FOLDER = ./libft

FLAGC = -Wall -Wextra -Werror

all: create_lib get_next_line

create_lib:
	gcc -I $(HEAD_FOLDER) -c $(SRC) $(FLAGC)
	ar rc $(NAME) $(FILE_O)
	ranlib $(NAME)
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~

get_next_line:
	gcc $(NAME_FILE) $(NAME) -o get_next_line

re_gnl:
	/bin/rm -f get_next_line
	gcc $(NAME_FILE) $(NAME) -o get_next_line
	
clean:
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~
	/bin/rm -f get_next_line

fclean: clean
	/bin/rm -rf $(NAME) get_next_line *~ 

re: fclean all get_next_line