# ===== Project =====
NAME        = tabulizer

# ===== Compiler =====
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
AR          = ar rcs

# ===== Directories =====
BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
LIB_DIR     = $(BUILD_DIR)/lib

# ===== Library Sources =====
LIB_SRCS = \
	src/border_style/BorderStyle.cpp \
	src/static_tabulizer/StaticTabulizer.cpp \
	src/static_tabulizer/StaticTabulizerPrivate.cpp \
	src/static_tabulizer/Cell.cpp \
	src/tabulizer_factory/TabulizerFactory.cpp

LIB_OBJS = $(LIB_SRCS:%.cpp=$(OBJ_DIR)/%.o)
LIB_TARGET = $(LIB_DIR)/lib$(NAME).a

# ===== Rules =====
all: dirs $(LIB_TARGET)

dirs:
	mkdir -p $(OBJ_DIR)/src/border_style
	mkdir -p $(OBJ_DIR)/src/static_tabulizer
	mkdir -p $(OBJ_DIR)/src/tabulizer_factory
	mkdir -p $(LIB_DIR)


# Build static library
$(LIB_TARGET): $(LIB_OBJS)
	$(AR) $@ $^


# Compile objects for library
$(OBJ_DIR)/src/border_style/BorderStyle.o: src/border_style/BorderStyle.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR)/src/static_tabulizer/StaticTabulizer.o: src/static_tabulizer/StaticTabulizer.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR)/src/static_tabulizer/StaticTabulizerPrivate.o: src/static_tabulizer/StaticTabulizerPrivate.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR)/src/static_tabulizer/Cell.o: src/static_tabulizer/Cell.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR)/src/tabulizer_factory/TabulizerFactory.o: src/tabulizer_factory/TabulizerFactory.cpp
	$(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

# ===== Clean =====
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re dirs
