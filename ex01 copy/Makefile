NAME			=	RPN
CXX				=	c++
CXXFLAG			=	-Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address
INCLUDES		=	./includes
SRCS_PATH		=	./srcs
OBJS_PATH		=	./objs
# SRCS			=	$(wildcard $(SRCS_PATH)/*.cpp)
SRCS			=	$(shell find $(SRCS_PATH) -name "*.cpp")
OBJS			=	$(patsubst $(SRCS_PATH)/%.cpp, $(OBJS_PATH)/%.o, $(SRCS))

RESET		=	\033[0m
GREEN		=	\033[38;5;46m
WHITE		=	\033[38;5;15m
GREY		=	\033[38;5;8m
ORANGE		=	\033[38;5;202m
RED			=	\033[38;5;160m

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CXX) $(CXXFLAG) -I$(INCLUDES) $^ -o $@

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.cpp ./Makefile $(INCLUDES) | ${OBJS_PATH}
					mkdir -p $(@D)
					$(CXX) $(CXXFLAG) -I$(INCLUDES) -c $< -o $@

$(OBJS_PATH)			:
							mkdir -p $(OBJS_PATH)

clean					:
							rm -rf $(OBJS_PATH)
						
fclean					:	clean
							rm -rf $(NAME)
						
re						:	fclean all

run						:	all
							./$(NAME)

valgrind				:
							valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt $(NAME)

.PHONY					:	clean fclean re run all valgrind