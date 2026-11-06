========================================================================
                      SECURITY LOG PARSER TOOL (CLI)
========================================================================

[OVERVIEW]
The Log File Parser is a command-line interface (CLI) tool written in C, 
designed specifically for Security Operations Center (SOC) analysts. 
It efficient scans large log files line-by-line to extract suspicious 
activities based on targeted security keywords (e.g., FAILED, 404, ERROR, 
UNAUTHORIZED).

------------------------------------------------------------------------
[KEY FEATURES]
- Memory Efficient: Processes log files line-by-line without loading 
  the entire file into memory (ideal for multi-gigabyte logs).
- Precise Tracking: Reports the exact line number of every detected match.
- Clean Output: Automatically strips line breaks for well-aligned report headers.
- Summary Report: Displays total lines scanned and total alerts triggered.

------------------------------------------------------------------------
[COMPILATION]
To compile the C code using GCC, run the following command in your terminal:

    gcc log_parser.c -o log_parser

------------------------------------------------------------------------
[USAGE & SYNTAX]
Run the executable by providing the target log file name and the keyword 
you wish to search for:

    log_parser <log_file_path> <keyword>

Examples:
1. Search for failed login attempts in Windows/Linux auth logs:
   log_parser auth.log FAILED

2. Search for HTTP 404 errors in web server logs:
   log_parser access.log 404

3. Search for unauthorized access warnings:
   log_parser system.log UNAUTHORIZED

------------------------------------------------------------------------
[SAMPLE OUTPUT]

=== Security Log Analysis Report ===
Target Keyword: [FAILED]
--------------------------------------------------
Line Number  | Suspicious Log Content
--------------------------------------------------
[Line 14    ] | 2026-11-06 10:15:22 User root: Password FAILED from 192.168.1.50
[Line 89    ] | 2026-11-06 10:42:01 User admin: Authentication FAILED
--------------------------------------------------
[+] Analysis Summary:
    - Total lines scanned: 120 lines
    - Total suspicious alerts found: 2 alerts
==================================================

------------------------------------------------------------------------
[REQUIREMENTS & COMPATIBILITY]
- Compiler: GCC / Clang / MSVC
- OS: Windows (CMD/PowerShell), Linux, macOS
- Dependencies: Standard C Libraries (stdio.h, stdlib.h, string.h)
========================================================================