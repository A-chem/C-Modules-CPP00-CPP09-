# =======================
#        SETTINGS
# =======================

NAME     = handleFile 
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS     = main.cpp
OBJS     = $(SRCS:.cpp=.o)

# =======================
#        COLORS
# =======================

GREEN    = \033[1;32m
YELLOW   = \033[1;33m
RED      = \033[1;31m
RESET    = \033[0m

# =======================
#       RULES
# =======================

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Build complete: $(NAME)$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing binary...$(RESET)"
	@rm -f $(NAME)

re: fclean all