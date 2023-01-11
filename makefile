SRCDIR	= srcs/
OBJDIR	= objs/
FUNC	= functions/
UTILS	= utils/
MAIN_WINDOW	= main_window/
SDL_HELPER = sdl_helper/
MATRIX	= matrix/
SHARED	= shared/
MAP		= map/

SRCS	=	$(addsuffix .cpp, \
		$(addprefix $(SRCDIR), \
			) \
		$(addprefix $(SRCDIR)$(FUNC), \
			)\
		$(addprefix $(SRCDIR)$(SHARED), \
			)\
		$(addprefix $(SRCDIR)$(UTILS), \
			)\
		$(addprefix $(SRCDIR)$(MAP), \
			)\
		$(addprefix $(SRCDIR)$(SDL_HELPER), \
			fatal_error)\
			\
		$(addprefix $(SRCDIR)$(MATRIX), \
			Matrix apply_translation op_equal op_multiply\
			op_ostream print_to)\
			\
		$(addprefix $(SRCDIR)$(MAIN_WINDOW), \
			MainWindow init_systems mainloop process_input run\
			draw_window\
			MouseState))

# get all cpp files
# @ls [path] | grep '\.cpp$' | sed 's/\.cpp$//' | tr '\n' ' ' && echo

OBJS	=	$(subst $(SRCDIR), $(OBJDIR), $(subst .cpp,.o,$(SRCS)))

CC				= clang++
INCLUDE_FLAGS	= -I/usr/include/SDL2 -I./include
LINKER_FLAGS	= -lSDL2 -lGL
CFLAGS			= #-Wall -Wextra -Werror -fsanitize=address
RM				= rm -rf
NAME			= vector

run: $(NAME)
	./$(NAME)
all: $(NAME)

$(NAME): $(OBJS) main.cpp
	$(CC) $(CFLAGS) $(OBJS) main.cpp $(INCLUDE_FLAGS) $(LINKER_FLAGS) -o $(NAME)
	
$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@$(shell mkdir -p $(@D))
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@echo "\033[1A\033[2K\033[1A"
clean:
	@$(RM) $(OBJS)
	
fclean:	clean
	@$(RM) $(OBJDIR)
	@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:			all clean fclean re .c.o
