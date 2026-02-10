#!/usr/bin/env python3

"""
generate_index.py - Generate unified problem index from sheet READMEs
Usage: python3 generate_index.py
"""

import os
import re
from pathlib import Path

def extract_problems_from_readme(readme_path):
    """Extract problem information from a README file."""
    problems = []
    
    if not os.path.exists(readme_path):
        return problems
    
    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Find problem tables in markdown
    # Look for lines like: | **A** | Problem Name | ⭐ Easy | Topics | O(N) | O(1) | [Link](...) | [Code](...) |
    pattern = r'\|\s*\*\*([A-Z])\*\*\s*\|\s*([^|]+)\|\s*([^|]+)\|\s*([^|]+)\|\s*([^|]+)\|\s*([^|]+)\|\s*\[Problem\]\(([^)]+)\)\s*\|\s*\[Code\]\(([^)]+)\)'
    
    matches = re.finditer(pattern, content)
    
    for match in matches:
        problem = {
            'id': match.group(1).strip(),
            'title': match.group(2).strip(),
            'difficulty': match.group(3).strip(),
            'topics': match.group(4).strip(),
            'time': match.group(5).strip(),
            'space': match.group(6).strip(),
            'link': match.group(7).strip(),
            'code': match.group(8).strip()
        }
        problems.append(problem)
    
    return problems

def get_sheet_info(sheet_dir):
    """Extract sheet name and number from directory name."""
    dir_name = os.path.basename(sheet_dir)
    
    # Extract sheet number and name
    match = re.match(r'(\d+)\s+(.+)', dir_name)
    if match:
        return {
            'number': match.group(1),
            'name': match.group(2),
            'dir': dir_name
        }
    return None

def generate_index(repo_path):
    """Generate unified problem index."""
    repo_path = Path(repo_path)
    
    # Find all sheet directories
    sheet_dirs = sorted([d for d in repo_path.iterdir() 
                        if d.is_dir() and (d.name.startswith('Sheet') or 'Sheet' in d.name)])
    
    # Also include numbered directories
    numbered_dirs = sorted([d for d in repo_path.iterdir() 
                           if d.is_dir() and d.name[0].isdigit()])
    
    all_dirs = numbered_dirs if numbered_dirs else sheet_dirs
    
    index_content = """# 📚 Complete Problem Index

This is a comprehensive index of all problems in the Assiut University Training repository, automatically generated from individual sheet READMEs.

**Total Sheets:** {total_sheets}  
**Total Problems:** {total_problems}

---

## 📋 Quick Navigation

{navigation}

---

"""
    
    sheet_sections = []
    navigation_links = []
    total_problems = 0
    
    for sheet_dir in all_dirs:
        readme_path = sheet_dir / 'README.md'
        
        if not readme_path.exists():
            continue
        
        sheet_info = get_sheet_info(str(sheet_dir))
        if not sheet_info:
            continue
        
        problems = extract_problems_from_readme(readme_path)
        
        if not problems:
            continue
        
        total_problems += len(problems)
        
        # Create navigation link
        sheet_anchor = sheet_info['name'].lower().replace(' ', '-').replace('#', '').replace('(', '').replace(')', '')
        navigation_links.append(f"- [{sheet_info['name']}](#{sheet_anchor})")
        
        # Create sheet section
        section = f"""## {sheet_info['name']}

**Directory:** `{sheet_info['dir']}/`  
**Problems:** {len(problems)}

| ID | Problem | Difficulty | Topics | Time | Space | Links |
|----|---------|------------|--------|------|-------|-------|
"""
        
        for prob in problems:
            section += f"| **{prob['id']}** | {prob['title']} | {prob['difficulty']} | {prob['topics']} | {prob['time']} | {prob['space']} | [Problem]({prob['link']}) • [Solution]({sheet_info['dir']}/{prob['code']}) |\n"
        
        section += "\n---\n\n"
        sheet_sections.append(section)
    
    # Fill in template
    navigation = '\n'.join(navigation_links)
    index_content = index_content.format(
        total_sheets=len(sheet_sections),
        total_problems=total_problems,
        navigation=navigation
    )
    
    index_content += ''.join(sheet_sections)
    
    # Add footer
    index_content += """---

## 🔍 Search Tips

- Use Ctrl+F (Cmd+F on Mac) to search for specific topics
- Filter by difficulty: ⭐ Easy, ⭐⭐ Medium, ⭐⭐⭐ Hard
- Look for specific algorithms in the Topics column

---

**Last Updated:** Auto-generated from sheet READMEs  
**Maintained by:** Assiut University Training Repository

[🏠 Back to Main README](README.md)
"""
    
    return index_content

if __name__ == '__main__':
    # Get repository root (parent of scripts directory)
    script_dir = Path(__file__).parent
    repo_root = script_dir.parent
    
    print(f"Generating problem index from: {repo_root}")
    
    index_content = generate_index(repo_root)
    
    output_file = repo_root / 'PROBLEMS.md'
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(index_content)
    
    print(f"✓ Generated: {output_file}")
    print(f"✓ Index created successfully!")
