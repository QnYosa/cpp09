NAME = RPN

SRCS = main.cpp RPN.cpp

INCLUDES = RPN.hpp 

OBJS = $(SRCS:%.cpp=%.o)

CXX = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CXX) $(CPPFLAGS) $(OBJS) -g -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY: re all clean fclean 