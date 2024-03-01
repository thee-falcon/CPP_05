# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 16:32:25 by omakran           #+#    #+#              #
#    Updated: 2024/03/01 16:33:47 by omakran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = Form

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS := $(SRCS:.cpp=.o)

CC = c++

CPPFLAGS = -std=c++98 -Wall -Werror -Wextra

all: $(EXEC)

$(EXEC):	$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(EXEC)

%.o:	%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re