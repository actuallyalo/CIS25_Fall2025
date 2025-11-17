This program simulates a mini banking system that lets a user manage two accounts — Checking and Savings — and automatically records all activity in a formatted transaction log (transactions.txt). It demonstrates classes, file I/O, formatted output, time-stamping, and menu-driven interaction.

Key Features

Two Bank Accounts
Checking
Savings
Each account stores a name and a balance.

Supported Banking Actions
Deposit money
Withdraw money
Make a purchase with an item name
Transfer money between accounts
Display balances
View a full session statement from the transactions.txt file

Automatic Transaction Logging
Every action is written to a file with:
Timestamp
Account
Transaction type (Deposit, Withdrawal, Purchase, Transfer)
Amount
Memo (such as item names or transfer direction)
Updated balance
This creates a clean, human-readable bank statement.

Session Header
Each time you run the program, it prints a new session header into the file with:
Start timestamp
Formatted table headers
Separator line
