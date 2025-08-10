# Compiler
CXX := c++

# Compiler flags
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Source files
SRCS := main.cpp \
		Base.cpp

# Object files directory
OBJDIR := objs

# Object files
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# Executable name
TARGET := identify

# Checkmark and color codes
CHECK = ✓
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

# Default target
all: $(TARGET)
	@echo "$(TARGET) compiled ${GREEN}$(CHECK)${RESET}"

# Create objects directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile source files into object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

# Clean object files and directory
clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@echo "Objects cleaned ${GREEN}$(CHECK)${RESET}"

# Clean everything including executable
fclean: clean
	@rm -f $(TARGET)
	@echo "$(TARGET) cleaned ${GREEN}$(CHECK)${RESET}"

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
