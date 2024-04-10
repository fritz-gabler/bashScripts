#!/bin/bash

# Save current directory
current_dir=$(pwd)

# Create directories
mkdir -p "$current_dir/src" "$current_dir/include" "$current_dir/include/objects" "$current_dir/src/objectFunctions"

# Create files
touch "$current_dir/include/header.hpp" "$current_dir/include/functions.hpp" "$current_dir/src/main.cpp"

# Create Makefile
cp ~/bashScripts/cppBash/files/Makefile "$current_dir/Makefile"
cp ~/bashScripts/cppBash/files/header.hpp "$current_dir/Makefile"
cp ~/bashScripts/cppBash/files/functions.hpp "$current_dir/Makefile"
