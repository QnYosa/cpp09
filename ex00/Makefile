NAME = btc

SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:%.cpp=%.o)

CXX = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

INCLUDES = BitcoinExchange.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CXX) $(CPPFLAGS) $(OBJS) -g -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: re all clean fclean