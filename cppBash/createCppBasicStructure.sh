#!/bin/bash

# Save current directory
current_dir=$(pwd)

# Create directories
mkdir -p "$current_dir/src" "$current_dir/include" "$current_dir/include/objects" "$current_dir/src/object_functions" "$current_dir/src/log_function"

# Create files
touch "$current_dir/include/header.hpp" "$current_dir/include/functions.hpp" "$current_dir/src/main.cpp"  "$current_dir/src/log_function/log.cpp" "$current_dir/include/colors.hpp" "$current_dir/include/define.hpp"  

# Create Makefile
cp ~/bashScripts/cppBash/files/Makefile "$current_dir/Makefile"
cp ~/bashScripts/cppBash/files/header.hpp "$current_dir/include/header.hpp"
cp ~/bashScripts/cppBash/files/functions.hpp "$current_dir/include/functions.hpp"
cp ~/bashScripts/cppBash/files/colors.hpp "$current_dir/include/colors.hpp"
cp ~/bashScripts/cppBash/files/define.hpp "$current_dir/include/define.hpp"
cp ~/bashScripts/cppBash/files/log.cpp "$current_dir/src/log_function/log.cpp"
cp ~/bashScripts/cppBash/files/.ccls "$current_dir"
