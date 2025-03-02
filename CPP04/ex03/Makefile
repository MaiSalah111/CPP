CPPFILES 	   = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp LinkedList.cpp \

CPP	= c++

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME	= Interface

all: $(NAME)

$(NAME): $(CPPFILES)
	$(CPP) $(CPPFLAGS) $(CPPFILES) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
