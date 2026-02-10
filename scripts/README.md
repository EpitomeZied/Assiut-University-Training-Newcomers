# 🛠️ Scripts Directory

This directory contains automation scripts to streamline your workflow when solving competitive programming problems.

## 📜 Available Scripts

### 1. compile.sh

**Purpose:** Quick compilation of C++ solutions with optimized flags.

**Usage:**

```bash
./scripts/compile.sh <source_file.cpp> [output_name]
```

**Examples:**

```bash
# Compile with default output name "solution"
./scripts/compile.sh "01 Sheet #1 (Data type - Conditions)/A. SayHelloWithCpp.cpp"

# Compile with custom output name
./scripts/compile.sh "03 Sheet #2 (Loops)/A. 1toN.cpp" my_solution
```

**Features:**

- C++17 standard
- O2 optimization
- Warning flags enabled (-Wall -Wextra)
- Color-coded output
- Error handling

---

### 2. test.sh

**Purpose:** Automated testing against input/output files.

**Usage:**

```bash
./scripts/test.sh <executable> <test_directory>
```

**Examples:**

```bash
# Run tests from a specific directory
./scripts/test.sh ./solution tests/sheet-1/A

# Test multiple cases
./scripts/test.sh ./my_solution tests/sheet-2/B
```

**Features:**

- Automatic input/output comparison
- Timeout protection (5 seconds per test)
- Color-coded pass/fail results
- Summary statistics

**Test File Format:**

- Input files: `*-input.txt` or `input*.txt`
- Output files: `*-output.txt` or `output*.txt`

---

### 3. generate_index.py

**Purpose:** Auto-generate unified problem index from README files.

**Usage:**

```bash
python3 scripts/generate_index.py
```

**Features:**

- Scans all sheet directories
- Extracts problem metadata from READMEs
- Generates `PROBLEMS.md` with complete index
- Includes links, difficulty, topics, and complexity

**Output:** Creates/updates `PROBLEMS.md` in repository root

---

### 4. check_progress.sh

**Purpose:** Track your problem-solving progress across all sheets.

**Usage:**

```bash
./scripts/check_progress.sh
```

**Features:**

- Counts solved problems per sheet
- Visual progress bar
- Completion statistics
- Color-coded status indicators

**Output Example:**

```
═══════════════════════════════════════════════
   Assiut University Training - Progress Tracker
═══════════════════════════════════════════════

01 Sheet #1 (Data type - Conditions)           26 problems  ✓ Complete
03 Sheet #2 (Loops)                            26 problems  ✓ Complete
...

═══════════════════════════════════════════════
Total Problems Solved: 261
═══════════════════════════════════════════════

Overall Progress: 100%
[██████████████████████████████████████████████████]
```

---

## 🚀 Quick Start

1. **Make scripts executable** (if not already):

   ```bash
   chmod +x scripts/*.sh
   ```

2. **Compile and run a solution**:

   ```bash
   ./scripts/compile.sh "03 Sheet #2 (Loops)/A. 1toN.cpp"
   ./solution
   ```

3. **Check your progress**:

   ```bash
   ./scripts/check_progress.sh
   ```

4. **Update problem index**:
   ```bash
   python3 scripts/generate_index.py
   ```

---

## 📝 Creating Test Cases

To use the testing script, create test files in this format:

```
tests/
├── sheet-1/
│   ├── A/
│   │   ├── 1-input.txt
│   │   ├── 1-output.txt
│   │   ├── 2-input.txt
│   │   └── 2-output.txt
│   └── B/
│       ├── sample-input.txt
│       └── sample-output.txt
└── sheet-2/
    └── ...
```

---

## 🔧 Customization

Feel free to modify these scripts to suit your workflow:

- **compile.sh**: Adjust compiler flags or add custom options
- **test.sh**: Change timeout duration or output format
- **generate_index.py**: Modify output format or add new fields
- **check_progress.sh**: Customize progress bar or statistics

---

## 🐛 Troubleshooting

### Script not executable

```bash
chmod +x scripts/<script_name>.sh
```

### Python script not found

Ensure Python 3 is installed:

```bash
python3 --version
```

### Compilation errors

Check that g++ is installed:

```bash
g++ --version
```

---

## 📚 Additional Resources

- [Main README](../README.md)
- [Problem Index](../PROBLEMS.md)
- [Templates](../templates/)
- [Utilities](../utils/)

---

**Happy Coding! 🚀**
