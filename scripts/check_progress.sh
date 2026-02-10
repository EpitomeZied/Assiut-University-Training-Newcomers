#!/bin/bash

# check_progress.sh - Track problem-solving progress
# Usage: ./check_progress.sh

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

echo -e "${BLUE}═══════════════════════════════════════════════${NC}"
echo -e "${BLUE}   Assiut University Training - Progress Tracker${NC}"
echo -e "${BLUE}═══════════════════════════════════════════════${NC}"
echo ""

TOTAL_PROBLEMS=0
TOTAL_SOLVED=0

# Get repository root
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

# Find all sheet directories
for dir in "$REPO_ROOT"/*/; do
    # Skip non-sheet directories
    dirname=$(basename "$dir")
    
    # Only process numbered directories (sheets and contests)
    if [[ ! "$dirname" =~ ^[0-9] ]]; then
        continue
    fi
    
    # Count C++ files (solutions)
    cpp_count=$(find "$dir" -maxdepth 1 -name "*.cpp" 2>/dev/null | wc -l)
    
    if [ $cpp_count -eq 0 ]; then
        continue
    fi
    
    TOTAL_PROBLEMS=$((TOTAL_PROBLEMS + cpp_count))
    TOTAL_SOLVED=$((TOTAL_SOLVED + cpp_count))
    
    # Calculate percentage
    percentage=100
    
    # Determine status color
    if [ $percentage -eq 100 ]; then
        status_color=$GREEN
        status="✓ Complete"
    elif [ $percentage -ge 50 ]; then
        status_color=$YELLOW
        status="◐ In Progress"
    else
        status_color=$CYAN
        status="○ Started"
    fi
    
    printf "${status_color}%-45s${NC} %3d problems  %s\n" "$dirname" "$cpp_count" "$status"
done

echo ""
echo -e "${BLUE}═══════════════════════════════════════════════${NC}"
echo -e "${GREEN}Total Problems Solved: $TOTAL_SOLVED${NC}"
echo -e "${BLUE}═══════════════════════════════════════════════${NC}"
echo ""

# Calculate overall percentage
if [ $TOTAL_PROBLEMS -gt 0 ]; then
    overall_percentage=$((TOTAL_SOLVED * 100 / TOTAL_PROBLEMS))
    echo -e "Overall Progress: ${GREEN}${overall_percentage}%${NC}"
    
    # Progress bar
    bar_length=50
    filled=$((overall_percentage * bar_length / 100))
    empty=$((bar_length - filled))
    
    printf "["
    printf "${GREEN}%${filled}s${NC}" | tr ' ' '█'
    printf "%${empty}s" | tr ' ' '░'
    printf "]\n"
fi

echo ""
