NAME = irc_commands

CXX = g++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -Iinc -O3 -g3 -fsanitize=address
LDFLAGS = -fsanitize=address

OBJ_DIR = obj/
SRC_DIR = src/

SRC_FILES = commands.cpp main.cpp msg.cpp replies_generator.cpp user.cpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.cpp=.o))

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

print:
	echo $(SRC)
	echo $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -Rf $(OBJ_DIR)
	rm $(NAME)


