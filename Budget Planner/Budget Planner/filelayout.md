Kenneth  Oluoch 
Team Based Software Development
July 13 2025

data                       Core data storage
 users.txt                User information
 transactions.bin        Binary transaction data
 budgets.txt             Budget records per user/category
 categories.txt           Optional spending categories
 settings.txt             User preferences

# File Layout for Budget Planner Application

# This document outlines the file structure for storing data in the Budget Planner application.


2. Naming Conventions
- Text files (.txt): for readable content like users, budgets, and categories.
- Binary files (.bin): for performance-heavy transactional data.
- Lowercase names: consistent formatting, underscores instead of spaces.
- No special characters: in file or directory names

structure


File Formats
- users.txt
user_id|name|email|password_hash|created_at
101|Jane Doe|jane@example.com|A9f4J...|2025-06-21
- transactions.bin
- Stored in binary format (e.g., using fwrite()/fread() in C)
- Each entry contains:

int transaction_id
int user_id
char date[11]     // "YYYY-MM-DD"
float amount
char category[20]
char note[100]


- budgets.txt
-user_id|category|budget_amount|period
101|groceries|300.00|monthly