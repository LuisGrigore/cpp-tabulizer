NAME = a

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = examples/main.cpp \
	   src/border_style/BorderStyle.cpp \
	   src/static_tabulizer/StaticTabulizer.cpp \
	   src/static_tabulizer/StaticTabulizerPrivate.cpp \
	   src/static_tabulizer/Cell.cpp \
	   src/tabulizer_factory/TabulizerFactory.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
