#!/bin/bash

# compile.sh - Quick compilation script for C++ competitive programming
# Usage: ./compile.sh <source_file.cpp> [output_name]

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Check if source file is provided
if [ $# -lt 1 ]; then
    echo -e "${RED}Error: No source file provided${NC}"
    echo "Usage: $0 <source_file.cpp> [output_name]"
    exit 1
fi

SOURCE_FILE="$1"
OUTPUT_NAME="${2:-solution}"

# Check if source file exists
if [ ! -f "$SOURCE_FILE" ]; then
    echo -e "${RED}Error: File '$SOURCE_FILE' not found${NC}"
    exit 1
fi

# Check if g++ is installed
if ! command -v g++ &> /dev/null; then
    echo -e "${RED}Error: g++ compiler not found${NC}"
    echo "Please install g++ to compile C++ programs"
    exit 1
fi

# Compile the program
echo -e "${YELLOW}Compiling: $SOURCE_FILE${NC}"
echo "Command: g++ -std=c++17 -O2 -Wall -Wextra \"$SOURCE_FILE\" -o \"$OUTPUT_NAME\""

if g++ -std=c++17 -O2 -Wall -Wextra "$SOURCE_FILE" -o "$OUTPUT_NAME"; then
    echo -e "${GREEN}✓ Compilation successful!${NC}"
    echo -e "${GREEN}Output: $OUTPUT_NAME${NC}"
    echo ""
    echo "Run with: ./$OUTPUT_NAME"
    echo "Run with input: ./$OUTPUT_NAME < input.txt"
    echo "Save output: ./$OUTPUT_NAME < input.txt > output.txt"
else
    echo -e "${RED}✗ Compilation failed${NC}"
    exit 1
fi
