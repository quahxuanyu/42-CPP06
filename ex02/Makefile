CXX = command /usr/bin/g++

CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

# Add Base.cpp to sources
SRC = srcs/utils.cpp srcs/main.cpp srcs/Base.cpp
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

# Target executable
TARGET = dynamic

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR) home_shrubbery

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re