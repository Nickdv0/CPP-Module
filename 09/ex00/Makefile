NAME = btc

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
SOURCES = main.cpp BitcoinExchange.cpp
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
	@echo "$(CYAN)Creating test files...$(NC)"
	@echo "date,exchange_rate" > data.csv
	@echo "2009-01-02,0" >> data.csv
	@echo "2011-01-03,0.3" >> data.csv
	@echo "2011-01-09,0.32" >> data.csv
	@echo "2012-01-11,7.1" >> data.csv
	@echo "2013-03-29,188.4" >> data.csv
	@echo "date | value" > input.txt
	@echo "2011-01-03 | 3" >> input.txt
	@echo "2011-01-03 | 2" >> input.txt
	@echo "2011-01-03 | 1" >> input.txt
	@echo "2011-01-03 | 1.2" >> input.txt
	@echo "2011-01-09 | 1" >> input.txt
	@echo "2012-01-11 | -1" >> input.txt
	@echo "2001-42-42" >> input.txt
	@echo "2012-01-11 | 1" >> input.txt
	@echo "2012-01-11 | 2147483648" >> input.txt
	@echo "$(GREEN)Running tests:$(NC)"
	@echo "$(YELLOW)Test 1: No arguments$(NC)"
	@./$(NAME) || true
	@echo "$(YELLOW)Test 2: Valid input file$(NC)"
	@./$(NAME) input.txt
	@echo "$(YELLOW)Test 3: Non-existent file$(NC)"
	@./$(NAME) nonexistent.txt || true

.PHONY: all clean fclean re test
