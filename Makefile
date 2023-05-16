NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -c -g

INCLUDES = -I $(HEADERS_DIRECTORY)

HEADERS_LIST = libft.h
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

ASCII_LIST = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_isascii.c
ASCII_DIRECTORY = ascii/
ASCII = $(addprefix $(ASCII_DIRECTORY), $(ASCII_LIST))

STRING_LIST = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_strchr.c \
				ft_strrchr.c ft_strcmp.c
STRING_DIRECTORY = string/
STRING = $(addprefix $(STRING_DIRECTORY), $(STRING_LIST))

SOURCES_LIST = $(ASCII) $(STRING) ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_substr.c ft_tolower.c \
		ft_toupper.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strnstr.c \
		ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_atoi.c ft_split.c ft_findchar.c \
		get_next_line.c convert_hex.c format_c.c format_d.c \
		format_i.c format_p.c format_s.c format_u.c format_x_big.c \
		format_x_small.c ft_printf.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SOURCES_DIRECTORY = sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;92m
RED = \033[0;91m
CYAN = \033[0;96m
BLUE = \033[0;94m
YELLOW = \033[0;93m
RESET = \033[0m

# ECHO 

ifeq "$(TERM)" "xterm-256color"
	ECHO = echo
else
	ECHO = echo -e
endif

# RULES

all: $(NAME) ## Compiles the project

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@$(ECHO) "\n\t$(CYAN)$(NAME): $(GREEN) objects files $(RESET)were created"
	@$(ECHO) "\t$(CYAN)$(NAME): $(GREEN)$(NAME)$(RESET) was created"
	@$(ECHO) "All done, now if the $(BLUE)FBI$(RESET) comes to your house, you can say you're innocent :D"
	
$(OBJECTS_DIRECTORY): ## Creates the objects directory and compiles all files to .o
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(ASCII_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)$(STRING_DIRECTORY)
	@$(ECHO) "What could go wrong in compiling all of this code:"
	@$(ECHO) "\t$(CYAN)$(NAME): $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created"
	@$(ECHO) "\t$(CYAN)$(NAME): $(GREEN)$(OBJECTS_DIRECTORY)$(ASCII_DIRECTORY)$(RESET) was birthed"
	@$(ECHO) "\t$(CYAN)$(NAME): $(GREEN)$(OBJECTS_DIRECTORY)$(STRING_DIRECTORY)$(RESET) has spawned"
	@$(ECHO) "Now a lot of commas will appear on your screen, don't worry it's just some silly things nothing incriminating :D"
	
$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@$(ECHO) "$(GREEN).$(RESET)\c"

clean: ## Cleans the project
	@rm -rf $(OBJECTS_DIRECTORY)
	@$(ECHO) "Deleting all object files, we can't let $(BLUE)FBI$(RESET) get all of this evidence:"
	@$(ECHO) "\t$(CYAN)$(NAME): $(RED)$(OBJECTS_DIRECTORY)$(RESET) was deleted"
	@$(ECHO) "\t$(CYAN)$(NAME): $(RED)$(OBJECTS_DIRECTORY)$(ASCII_DIRECTORY)$(RESET) was evaporated"	
	@$(ECHO) "\t$(CYAN)$(NAME): $(RED)object files$(RESET) were annihilated"
	@$(ECHO) "Now you can see the $(YELLOW)light$(RESET) of day"

fclean: clean ## Deep cleans the project
	@rm -f $(NAME)
	@$(ECHO) "\nBurning the last thing that connects me to this project:"
	@$(ECHO) "\t$(CYAN)$(NAME): $(RED)$(NAME)$(RESET) was erased from the world surface"

re: fclean all ## Deep cleans and recompiles the project
	

help: ## Shows all the options and it's uses
	@echo "Usage: make [target]"
	@echo ""
	@egrep "^(.+)\:\ .*##\ (.+)" ${MAKEFILE_LIST} | sed 's/:.*##/#/' | column -t -c 2 -s '#'

.PHONY: all clean fclean re help

