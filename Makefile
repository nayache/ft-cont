# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 16:09:23 by nayache           #+#    #+#              #
#    Updated: 2022/04/29 19:34:27 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= std_containers_test

NAME2	= ft_containers_test

SRCS	= test.cpp

OBJS	= $(SRCS:test.cpp=STD_TEST.o)

OBJS2	= $(SRCS:test.cpp=FT_TEST.o)

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -D STACK=std::stack \
			-D VECTOR=std::vector -D PAIR=std::pair -D MAP=std::map

CFLAGS2	= -Wall -Wextra -Werror -std=c++98 -D STACK=ft::stack \
			-D VECTOR=ft::vector -D PAIR=ft::pair -D MAP=ft::map

all		:	std ft

STD_TEST.o:	test.cpp
		$(CC) $(CFLAGS) $(INC) -I includes/ -c $< -o $@

FT_TEST.o:	test.cpp
		$(CC) $(CFLAGS2) $(INC) -I includes/ -c $< -o $@

$(NAME1): 	$(OBJS)
			$(CC) $(OBJS) -o $@
			@echo "\e[32mstd_containers_test\e[0m is generated\n"

$(NAME2): 	$(OBJS2)
			$(CC) $(OBJS2) -o $@
			@echo "\e[32mft_containers_test\e[0m is generated\n"

std		:	$(NAME1)

ft		:	$(NAME2)

test	:	all
			@echo "\e[107m\e[1;30m RUN TESTS && COMPARE OUTPUTS \e[0m\n"
			@time ./std_containers_test
			@echo
			@mv log log1
			@time ./ft_containers_test
			@echo
			diff log log1
clean	:
			rm -rf $(OBJS)
			rm -rf $(OBJS2)

fclean	:	clean
			rm -rf $(NAME1)
			rm -rf $(NAME2)

re		:	fclean all

.PHONY	: all clean fclean re std ft
