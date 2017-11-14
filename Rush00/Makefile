NAME = game
FLAGS = -Wall -Werror -Wextra
SRC = 	Display.cpp \
		Game.cpp \
		main.cpp \
		Bullet.cpp \
		Entry.cpp \
		Medical_help.cpp \
		Shield.cpp \
		Damage.cpp \
		Enemy.cpp \
		Player.cpp \
		SpaceObject.cpp
OBJ = $(SRC:.cpp=.o)
LIB = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(LIB) $(OBJ) -o $(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -c -o $@ $<

clean:
	rm  -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
