NAME = Cub3D

BASE_SRC = \
	ft_err.c \
	get_conf_fd.c \

MAIN_SRC = \
	main.c \

TEST_SRC = \
	GetConfFdTest.cpp \
	fakes/OpenFake.cpp \

BASE_OBJ = $(BASE_SRC:%=$(OBJ_DIR)/$(SRC_DIR)/%.o)
MAIN_OBJ = $(MAIN_SRC:%=$(OBJ_DIR)/$(SRC_DIR)/%.o) $(BASE_OBJ)
TEST_OBJ = $(TEST_SRC:%=$(OBJ_DIR)/$(TEST_DIR)/%.o) $(BASE_OBJ)

SRC_DIR = src
INC_DIR = inc
TEST_DIR = test
OBJ_DIR = obj
LIBFT_DIR = libft
TEST_FILENAME = run_tests

LIBFT = $(LIBFT_DIR)/libft.a

MAKE = make
MAKE_LIBFT = $(MAKE) -C $(LIBFT_DIR)
MKDIR = mkdir -p
RM = rm -rf

CC = gcc
CXX = g++
LD = g++
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)
CPPFLAGS = -c $(INCLUDES) -Wall -Wextra -Werror
LDFLAGS = $(INCLUDES) -L$(LIBFT_DIR)
LDLIBS = -lft -lmlx -lXext -lX11 -lgtest -lgtest_main

.PHONY: all bonus clean fclean re test

.SECONDEXPANSION:

all bonus: $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME): $(LIBFT) $(MAIN_OBJ)
	$(LD) $(LDFLAGS) $(MAIN_OBJ) $(LDLIBS) -o $(NAME)

sclean:
	$(RM) $(OBJ_DIR)

clean: sclean
	$(MAKE_LIBFT) fclean

fclean: clean
	$(RM) $(NAME)

sre: sclean all

re: fclean all

test: $(TEST_FILENAME)
	./$(TEST_FILENAME)

$(TEST_FILENAME): $(LIBFT) $(TEST_OBJ)
	$(LD) $(LDFLAGS) $(TEST_OBJ) $(LDLIBS) -o $(TEST_FILENAME)

retest: sclean test

%/:
	$(MKDIR) $@

$(OBJ_DIR)/%.c.o: %.c | $$(dir $(OBJ_DIR)/%)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< $(LDLIBS) -o $@

$(OBJ_DIR)/%.cpp.o: %.cpp | $$(dir $(OBJ_DIR)/%)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< $(LDLIBS) -o $@
