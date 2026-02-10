#!/bin/bash

# test.sh - Automated testing script for competitive programming solutions
# Usage: ./test.sh <executable> <test_directory>

set -e

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

if [ $# -lt 2 ]; then
    echo -e "${RED}Error: Missing arguments${NC}"
    echo "Usage: $0 <executable> <test_directory>"
    echo "Example: $0 ./solution tests/sheet-1/A"
    exit 1
fi

EXECUTABLE="$1"
TEST_DIR="$2"

if [ ! -f "$EXECUTABLE" ]; then
    echo -e "${RED}Error: Executable '$EXECUTABLE' not found${NC}"
    exit 1
fi

if [ ! -d "$TEST_DIR" ]; then
    echo -e "${RED}Error: Test directory '$TEST_DIR' not found${NC}"
    exit 1
fi

# Make executable if needed
chmod +x "$EXECUTABLE"

echo -e "${BLUE}Running tests from: $TEST_DIR${NC}"
echo "================================"

PASSED=0
FAILED=0
TOTAL=0

# Find all input files
for input_file in "$TEST_DIR"/*-input.txt "$TEST_DIR"/input*.txt; do
    if [ ! -f "$input_file" ]; then
        continue
    fi
    
    TOTAL=$((TOTAL + 1))
    
    # Determine expected output file
    output_file="${input_file//-input.txt/-output.txt}"
    output_file="${output_file//input/output}"
    
    if [ ! -f "$output_file" ]; then
        echo -e "${YELLOW}⚠ Test $(basename "$input_file"): No expected output file${NC}"
        continue
    fi
    
    # Run the program
    actual_output=$(timeout 5s "$EXECUTABLE" < "$input_file" 2>/dev/null || echo "TIMEOUT/ERROR")
    expected_output=$(cat "$output_file")
    
    # Compare outputs
    if [ "$actual_output" = "$expected_output" ]; then
        echo -e "${GREEN}✓ Test $(basename "$input_file"): PASSED${NC}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗ Test $(basename "$input_file"): FAILED${NC}"
        echo "  Expected: $expected_output"
        echo "  Got:      $actual_output"
        FAILED=$((FAILED + 1))
    fi
done

echo "================================"
echo -e "Total: $TOTAL | ${GREEN}Passed: $PASSED${NC} | ${RED}Failed: $FAILED${NC}"

if [ $FAILED -eq 0 ] && [ $TOTAL -gt 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    exit 1
fi
