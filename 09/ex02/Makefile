NAME = PmergeMe

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
SOURCES = main.cpp PmergeMe.cpp
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
	@echo "$(GREEN)Running PmergeMe tests:$(NC)"
	@echo "$(YELLOW)Test 1: Small sequence$(NC)"
	@./$(NAME) 3 5 9 7 4
	@echo ""
	@echo "$(YELLOW)Test 2: Single element$(NC)"
	@./$(NAME) 42
	@echo ""
	@echo "$(YELLOW)Test 3: Two elements$(NC)"
	@./$(NAME) 5 2
	@echo ""
	@echo "$(YELLOW)Test 4: Larger sequence$(NC)"
	@./$(NAME) 1 5 2 8 3 7 4 6 9
	@echo ""
	@echo "$(YELLOW)Test 5: Invalid input (negative)$(NC)"
	@./$(NAME) -1 2 || true
	@echo ""
	@echo "$(YELLOW)Test 6: Invalid input (non-numeric)$(NC)"
	@./$(NAME) abc 123 || true
	@echo ""
	@echo "$(YELLOW)Test 7: No arguments$(NC)"
	@./$(NAME) || true

test-large: $(NAME)
	@echo "$(PURPLE)Testing $(NAME) with large dataset...$(NC)"
	@echo "$(YELLOW)Generating 100 random numbers:$(NC)"
	@$(eval NUMS := $(shell seq 1 100 | shuf | tr '\n' ' '))
	@./$(NAME) $(NUMS)

.PHONY: all clean fclean re test test-large
