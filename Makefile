# GNU PARAMETERS
NAME	:=	libftprintf.a
CFLAGS	:=	-Werror -Wextra -Wall -g -w
CC		:=	gcc

# INCLUDES
INC_DIR     := 	includes
INCS		:=  -I $(INC_DIR)

# SOURCES
SRCS_DIR :=	srcs
SRCS	:=		ft_printf.c															\
				format/ft_format.c													\
				format/ft_format_router.c											\
				format/utils/decimal/ft_format_width_handler.c						\
				format/utils/decimal/ft_format_plus_flag_handler.c					\
				format/utils/decimal/ft_format_moins_flag_handler.c					\
				format/utils/decimal/ft_format_space_flag_handler.c					\
				format/utils/decimal/ft_format_moins_flag_space_or_plus_handler.c	\
				format/utils/decimal/ft_format_precision_handler.c					\
				format/utils/decimal/ft_format_precison_width_handler.c				\
				format/utils/decimal/ft_format_precision_moins_flag_handler.c		\
				format/utils/decimal/ft_format_null_value.c							\
				format/utils/hex/ft_format_hex_null_value.c							\
				format/utils/hex/ft_format_hex_precision_handler.c					\
				format/utils/hex/ft_format_hex_precision_moins_flag_handler.c		\
				format/utils/hex/ft_format_hex_precision_width_handler.c			\
				format/utils/hex/ft_format_hex_width_handler.c						\
				format/utils/hex/ft_format_hex_width_zero_flag.c					\
				format/utils/hex/ft_format_hex_moins_flag_handler.c					\
				format/utils/str/ft_format_str_flags.c								\
				format/utils/str/ft_format_str_width_handler.c						\
				format/utils/str/ft_format_str_precision_handler.c					\
				format/utils/str/ft_format_str_moins_flag_handler.c					\
				format/utils/wstr/ft_format_wstr_flags.c							\
				format/utils/wstr/ft_format_wstr_width_handler.c					\
				format/utils/wstr/ft_format_wstr_precision_handler.c				\
				format/utils/wstr/ft_format_wstr_moins_flag_handler.c				\
				format/formatters/ft_format_int.c									\
				format/formatters/ft_format_u_int.c									\
				format/formatters/ft_format_hex.c									\
				format/formatters/ft_format_char.c									\
				format/formatters/ft_format_str.c									\
				format/formatters/ft_format_percent.c								\
				parser/ft_parser.c													\
				parser/utils/ft_parser_find_regex.c									\
				parser/utils/ft_parser_options_checker.c							\
				parser/utils/ft_parser_get_precision.c								\
				parser/utils/ft_parser_get_regex_len.c								\
				parser/utils/ft_parser_get_width.c									\
				parser/utils/ft_parser_get_width_precision.c						\
				parser/utils/ft_parser_get_text_and_expression.c					\
				parser/utils/ft_parser_get_zero_flag_width.c						\
				parser/utils/ft_parser_get_zero_flag_width_precision.c				\
				parser/utils/ft_parser_put_default.c								\
				printer/ft_printer.c												\
				counter/ft_counter.c												\
				printer/utils/ft_print_null_bite.c									\
				printer/utils/ft_print_unicode.c									\
				printer/utils/ft_print_wchar.c										\
				utils/list/ft_list_append.c											\
				utils/list/ft_init_values.c											\
				utils/list/ft_list_create_data_elem.c								\
				utils/test/ft_test_print_list_elem.c								\
				utils/test/ft_test_print_list.c										\
				utils/free/ft_free_structure.c										\
				utils/libft/ft_abs_intmax.c											\
				utils/libft/ft_atoi.c												\
				utils/libft/ft_bzero.c												\
				utils/libft/ft_cutstr.c												\
				utils/libft/ft_fillit.c												\
				utils/libft/ft_isalpha.c											\
				utils/libft/ft_islower.c											\
				utils/libft/ft_isupper.c											\
				utils/libft/ft_itoa_base_intmax.c									\
				utils/libft/ft_itoa_base_uintmax.c									\
				utils/libft/ft_memalloc.c											\
				utils/libft/ft_memdel.c												\
				utils/libft/ft_memset.c												\
				utils/libft/ft_putchar.c											\
				utils/libft/ft_putstr.c												\
				utils/libft/ft_putwchar.c											\
				utils/libft/ft_strcat.c												\
				utils/libft/ft_strcut.c												\
				utils/libft/ft_strdel.c												\
				utils/libft/ft_strdup.c												\
				utils/libft/ft_strhas_char.c										\
				utils/libft/ft_strhas_digit.c										\
				utils/libft/ft_strhas_str.c											\
				utils/libft/ft_strhas_zero.c										\
				utils/libft/ft_strjoin.c											\
				utils/libft/ft_strlen.c												\
				utils/libft/ft_strnew.c												\
				utils/libft/ft_strncut.c											\
				utils/libft/ft_strreplace.c											\
				utils/libft/ft_strtoupper.c											\
				utils/libft/ft_toupper.c											\
				utils/libft/ft_wbzero.c												\
				utils/libft/ft_strwlen.c											\
				utils/libft/ft_wcharlen.c											\

SRCS_FILES 	:= $(addprefix $(SRCS_DIR)/,$(SRCS))

# OBJECTS
OBJ_DIR		:=	obj
CREATE_DIR	:=  $(OBJ_DIR)							\
				$(OBJ_DIR)/format					\
				$(OBJ_DIR)/format/formatters		\
				$(OBJ_DIR)/format/utils/decimal		\
				$(OBJ_DIR)/format/utils/hex			\
				$(OBJ_DIR)/format/utils/str			\
				$(OBJ_DIR)/format/utils/wstr		\
				$(OBJ_DIR)/parser/					\
				$(OBJ_DIR)/parser/utils				\
				$(OBJ_DIR)/counter					\
				$(OBJ_DIR)/printer					\
				$(OBJ_DIR)/printer/utils			\
				$(OBJ_DIR)/utils/free				\
				$(OBJ_DIR)/utils/list				\
				$(OBJ_DIR)/utils/test				\
				$(OBJ_DIR)/utils/libft				\

OBJS		:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

AR		:=	ar rc

RL		:=	ranlib

# TERMINAL COMMANDS
RM			:= /bin/rm -rf

# COLORS
LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m
LOG_CLIGNO		= \033[5m

.PHONY: all clean fclean re norme create-folder

all : create-folder $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RL) $(NAME) 
	@echo "\033[5m$(LOG_GREEN)$(NAME) CREATED SUCCESSFULLY$(LOG_NOCOLOR)"

create-folder : $(CREATE_DIR)

$(CREATE_DIR) :
	@echo ""
	@echo ""
	@echo "$(LOG_VIOLET) $(LOG_CLIGNO)BEGIN COMPILING $(NAME)...$(LOG_NOCOLOR)"
	@mkdir -p $(CREATE_DIR)

$(OBJ_DIR)/%.o	:  $(SRCS_DIR)/%.c
	@echo "$(LOG_CLEAR)	👉  add $@	✅ $(LOG_NOCOLOR)"
	@$(CC) $(CFLAGS) -o $@ -c $<  $(INCS) $(LIB_LINK)
	
norme :
	@clear
	@norminette $(SRCS)
	@norminette $(INC_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(LOG_CLEAR)$(LOG_RED)OBJECT FILES GO TO 🗑️$(LOG_NOCOLOR)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(LOG_RED)REMOVE $(NAME) SUCCESSFULLY 🗑️$(LOG_NOCOLOR)"
	@echo ""
	@echo ""

re : fclean all
