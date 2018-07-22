# GNU PARAMETERS
NAME	:=	ftprintf
#CFLAGS	:=	-Werror -Wextra -Wall
CFLAGS  :=  -g
CC		:=	gcc

# LIBRARIES
LIB_PATH	:=	libft
LIB			:=	$(LIB_PATH)/libft.a
LIB_LINK	:=	-L $(LIB_PATH) -lft

# INCLUDES
INCS		:=	-I $(LIB_PATH) -I $(SRCS_DIR)

# SOURCES
SRCS_DIR :=	srcs
SRCS	:=		main.c												\
				ft_printf.c											\
				format/ft_format.c									\
				format/ft_format_router.c							\
				format/ft_format_width_handler.c					\
				format/ft_format_plus_flag_handler.c				\
				format/ft_format_moins_flag_handler.c				\
				format/ft_format_space_flag_handler.c				\
				format/ft_format_moins_flag_space_or_plus_handler.c	\
				format/formatters/ft_format_int.c					\
				format/formatters/ft_format_hex.c					\
				parser/ft_parser.c									\
				parser/utils/ft_parser_find_regex.c					\
				parser/utils/ft_parser_options_checker.c			\
				parser/utils/ft_parser_get_precision.c				\
				parser/utils/ft_parser_get_regex_len.c				\
				parser/utils/ft_parser_get_width.c					\
				parser/utils/ft_parser_get_text_and_expression.c	\
				parser/utils/ft_parser_get_zero_flag_width.c		\
				parser/utils/ft_parser_put_default.c				\
				printer/ft_printer.c								\
				utils/list/ft_list_append.c							\
				utils/list/ft_list_create_data_elem.c				\
				utils/test/ft_test_print_list_elem.c				\
				utils/test/ft_test_print_list.c						\
				# parser/utils/va_arg/ft_parser_va_arg_get_argument.c \
				# parser/utils/va_arg/ft_parser_va_arg_get_double_arg.c \
				# parser/utils/va_arg/ft_parser_va_arg_get_int_arg.c \
				# parser/utils/va_arg/ft_parser_va_arg_get_string_arg.c \
				# test/test_format.c			\
				
				# format/ft_formatter.c \

SRCS_FILES 	:= $(addprefix $(SRCS_DIR)/,$(SRCS))
# OBJECTS
OBJS		:=	$(SRCS_FILES:.c=.o)

# TERMINAL COMMANDS
RM			:= /bin/rm -rf

# COLORS
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m

.PHONY: clean fclean re norme

all : $(NAME)

$(NAME) : $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)
	@echo "$(LOG_GREEN)$(NAME) CREATED SUCCESSFULLY$(LOG_NOCOLOR)"

$(LIB)	:
	@echo "$(LOG_CLEAR)$(LOG_VIOLET)$(LOG_BOLD)BEGIN COMPILING ...$(LOG_NOCOLOR)"
	@make -C $(LIB_PATH)

%.o		: $(SRCS_DIR)/%.c
	@echo "$(LOG_CLEAR)	👉  add $@	✅ $(LOG_NOCOLOR)"
	@$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	
norme :
	@clear
	@make norme -C $(LIB_PATH)
	@norminette $(SRCS)
	@norminette $(INC_DIR)

clean:
	@$(RM) $(OBJS)
	@make fclean -C $(LIB_PATH)
	@echo "$(LOG_CLEAR)$(LOG_RED)OBJECT FILES GO TO 🗑️$(LOG_NOCOLOR)"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(LOG_RED)REMOVE $(NAME) SUCCESSFULLY 🗑️$(LOG_NOCOLOR)"
	@echo ""
	@echo ""

re : fclean all