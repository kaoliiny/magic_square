.PHONY: all clean fclean re mclean mfclean mre

NAME = magic_square

CC = clang
CFLAGS = -Wall -Werror -Wextra

SRC_PATH = src/
OBJ_PATH = .obj/

INC_PATH = includes/
IFLAGS = -I $(INC_PATH) -I /Library/Frameworks/SDL2.framework/Headers/
SDL = -F /Library/Frameworks -framework SDL2 #`sdl2-config --cflags --libs`

HFILES = magic_square
FILES = magic_square
LIB = $(LIB_PATH)libftprintf.a

HDRS = $(addprefix $(INC_PATH), $(addsuffix .hpp, $(HFILES)))
SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(FILES)))
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(SDL) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
fclean: mfclean
re: fclean all

mclean:
	rm -f $(OBJS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all
