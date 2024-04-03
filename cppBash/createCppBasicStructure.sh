#!/bin/bash

# Save current directory
current_dir=$(pwd)

# Create directories
mkdir -p "$current_dir/src" "$current_dir/include" "$current_dir/include/objects"

# Create files
touch "$current_dir/include/header.hpp" "$current_dir/include/functions.hpp" "$current_dir/src/main.cpp"

# Create Makefile
cat <<EOF > "$current_dir/Makefile"
NAME                    =               changeName

###############################################################################
###############################################################################

CC                              =               c++
CFLAGS                  =               -Wall -Werror -Wextra
CPPFLAG                 =               -std=c++98
HEADERS                 =               -I./include -I./include/objects

###############################################################################
###############################################################################

SRC_MEGAPHONE   =               megaphone.cpp
SRC                             =               \$(SRC_MEGAPHONE)

###############################################################################
###############################################################################

OBJ_DIR                 :=              ./_obj
OBJ                             :=              \$(addprefix \$(OBJ_DIR)/, \$(SRC:%.cpp=%.o))

###############################################################################
###############################################################################

all:            \$(NAME)

\$(NAME):        \$(LIBS_NAME) \$(OBJ)
        @echo   \$(YELLOW)Compiling [\$(NAME)]...\$(RESET)
        @\$(CC)  \$(CFLAGS) \$(CPPFLAG) \$(OBJ) -o \$(NAME)
        @echo   \$(GREEN)Success [\$(NAME)] is compiled\$(RESET)

\$(OBJ_DIR)/%.o: %.cpp
        @mkdir -p _obj
        @\$(CC) \$(CFLAGS) -c \$< \$(HEADERS) -o \$@

###############################################################################
###############################################################################
clean:
        @if [ -d "\${OBJ_DIR}" ]; then                                          \
                echo \$(RED)Cleaning"  "[\$(OBJ_DIR)]...\$(RESET); \
                rm -rf \${OBJ_DIR};                                             \
                echo \$(GREEN)Cleaned!\$(RESET);                                 \
        fi

fclean:         clean
        @echo \$(RED)Cleaning executables...
        @printf \$(UP)\$(CUT)
        @if [ -f "\$(NAME)" ]; then                                             \
                echo \$(RED)Cleaning"  "[\$(NAME)]...\$(RESET);    \
                rm -f \$(NAME);                                                 \
                echo \$(GREEN)Cleaned!\$(RESET);                                 \
        fi

re: fclean all

###############################################################################
###############################################################################

YELLOW          :=                      "\033[33m"
RED                     :=                      "\033[33m"
GREEN           :=                      "\033[32m"
RESET           :=                      "\033[0m"
UP                      :=                      "\033[A"
CUT                     :=                      "\033[K"

###############################################################################
###############################################################################

.PHONY: all clean fclean re bonus
EOF

