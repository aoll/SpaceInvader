EXEC=ft_retro
CXX=g++
CXXFLAGS=
LIB=-lncurses
SRC=class/Hero.class.cpp class/Shoot2.class.cpp class/Rock.class.cpp class/Ship.class.cpp main.cpp class/Game.Class.cpp\
		class/Vilain.class.cpp class/Shoot.class.cpp
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LIB)

%.o: %.c
	$(CXX) $(CXXFLAGS) -o &@ -c $<

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
