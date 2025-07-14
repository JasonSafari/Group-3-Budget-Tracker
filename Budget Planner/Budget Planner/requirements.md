# Requirements for File Storage (v1.0)
Kenneth Oluoch
Team Based Software Development
July 12 2025
Defines essential data structures for user info, transactions, budgets, and more.

1. Users
Stores data for individuals using the application.
- user_id (int): unique identifier
- name (string)
- email (string)
- password_hash (string): hashed for security
- Optional: account_creation_date

2. Transactions
Logs every financial transaction.
- transaction_id (int): unique identifier
- user_id (int): links to the owner
- date (YYYY-MM-DD)
- amount (float)
- category (string): e.g., groceries, rent
- note (string): optional user note

 3. Budgets
 Tracks user budget goals per category.
- user_id (int)
- category (string)
- budget_amount (float)
- budget_period (string): monthly, weekly, etc.

4. Categories
Helps users organize spending.
- category_name (string)

- 5. Settings
- Handles app preferences for each user.
- user_id (int)
- currency (string): e.g., USD, CAD
- theme (string): e.g., light/dark mode

	

