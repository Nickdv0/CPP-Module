# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Source files
SRCS := megaphone.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable name
TARGET := megaphone

# Default target
all: $(TARGET)

#checkmark
CHECK = ✓

#colour codes
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

# Compile source files into object files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(TARGET) compiled		${GREEN}$(CHECK)${RESET}"

# Link object files into executable
$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

# Clean object files and executable
clean:
	@rm -f $(OBJS)
	@echo "Objects cleaned			${GREEN}$(CHECK)${RESET}"

# Clean object files, executable, and additional generated files
fclean: clean
	@rm -f $(TARGET)
	@echo "$(TARGET) cleaned		${GREEN}$(CHECK)${RESET}"

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re