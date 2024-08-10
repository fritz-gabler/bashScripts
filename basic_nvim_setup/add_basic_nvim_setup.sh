#!/bin/bash

# Save current directory
current_dir=$(pwd)
scriptPath="$HOME/bashScripts/basic_nvim_setup"

# Find all hpp files and save in file
find . -iname "*.hpp" > "$scriptPath/pathCreation/textFiles/hppPath.txt"

# Call program to clean Paths
cd "$scriptPath"
"$scriptPath/pathCreation/pathManipulation/cleanPath"
cd - > /dev/null 2>&1

# Check if cleanCclsPath.txt was created
if [ ! -f "$scriptPath/pathCreation/textFiles/cleanCclsPath.txt" ]; then
    echo "Error: cleanCclsPath.txt was not created."
    exit 1
fi

# Create .ccls file
cp ~/bashScripts/basic_nvim_setup/ccls_file/.ccls "$current_dir/.ccls"

# Add *hpp file paths to ccls file
cat "$scriptPath/pathCreation/textFiles/cleanCclsPath.txt" >> "$current_dir/.ccls"
rm "$scriptPath/pathCreation/textFiles/cleanCclsPath.txt"

