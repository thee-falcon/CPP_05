# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakran <omakran@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 17:16:18 by omakran           #+#    #+#              #
#    Updated: 2024/03/07 17:18:05 by omakran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = AForm

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

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