NAME = RPN

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NC = \033[0m

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCDIR = .
SOURCES = main.cpp RPN.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(CYAN)Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

%.o: %.cpp
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)Cleaning executable...$(NC)"
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(PURPLE)Testing $(NAME)...$(NC)"
	@echo "$(GREEN)Running RPN tests:$(NC)"
	@echo "$(YELLOW)Test 1: 8 9 * 9 - 9 - 9 - 4 - 1 +$(NC)"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "$(YELLOW)Test 2: 7 7 * 7 -$(NC)"
	@./$(NAME) "7 7 * 7 -"
	@echo "$(YELLOW)Test 3: 1 2 * 2 / 2 * 2 4 - +$(NC)"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo "$(YELLOW)Test 4: Invalid expression with brackets$(NC)"
	@./$(NAME) "(1 + 1)" || true
	@echo "$(YELLOW)Test 5: Simple addition$(NC)"
	@./$(NAME) "1 2 +"
	@echo "$(YELLOW)Test 6: Division$(NC)"
	@./$(NAME) "8 2 /"
	@echo "$(YELLOW)Test 7: Invalid number (too many digits)$(NC)"
	@./$(NAME) "10 2 +" || true
	@echo "$(YELLOW)Test 8: Insufficient operands$(NC)"
	@./$(NAME) "1 +" || true

.PHONY: all clean fclean re test
