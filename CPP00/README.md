# CPP-Module-00
🔹 Step 1: Understand the Goal

. This module is your first step in C++.

. It's based on C++98 standard (not modern C++11 or later).

. You’ll learn the basics of:

    . Namespaces
    
    . Classes
    
    . Member functions
    
    . Static & const keywords
    
    . Initialization lists
    
    . stdio streams (std::cout, std::cin, etc.)
    

🔹 Step 2: Follow General Rules

. Compilation Flags: Always compile using:

    ** c++ -Wall -Wextra -Werror -std=c++98 ** 
    
. Naming & Formatting:

    . Directory names: ex00, ex01, etc.
    
    . Class name: UpperCamelCase (e.g. MyClass.hpp)
    
    . Headers must have include guards.
    
    . No C functions like printf, malloc, free.
    
. Don't use:

    . using namespace std;
    
    . friend keyword
    
    . STL containers or algorithms (like vector, map, etc.)
    

🔸 🔸 Exercise 00: Megaphone 

📝 Objective

Write a C++ program that:

    1. Takes one or more command-line arguments (strings)
    
    2. Converts them to uppercase
    
    3. Prints the result to standard output
    

If no arguments are given, print:

    ** LOUD AND UNBEARABLE FEEDBACK NOISE **

📂 Turn-in Requirements

. Folder: ex00/

. Files to submit:

    . megaphone.cpp
    
    . Makefile
    

✅ Expected Behavior

1. If arguments are passed:
   
    $> ./megaphone Hello there!
   
    → HELLO THERE!
   
4. If no arguments are passed:
   
    $> ./megaphone
   
    → * LOUD AND UNBEARABLE FEEDBACK NOISE *


🔸 Exercise 01: My Awesome PhoneBook

📂 Turn-in Folder

. Directory: ex01/

. Files:

    . Makefile
    
    . One or more .cpp files (for logic)
    
    . hpp (or .h) headers (for class declarations)
    

🧠 Goal of This Project

You must build a command-line phonebook application using:

. Two classes: PhoneBook and Contact

. A maximum of 8 contacts

. A simple text-based user interface to:

    . ADD a contact
    
    . SEARCH for a contact by index
    
    . EXIT to quit
    

🔹 Step 1: Understand the Program Flow

When the program runs:

. It starts empty

. It enters a loop asking for one of these commands: ADD, SEARCH, or EXIT

. Based on the command:

    . ADD → prompts user to fill 5 fields
    
    . SEARCH → displays a table and asks for an index to show contact
    
    . EXIT → exits program

🔹 Step 2: Create Class Contact

This class stores one contact's data:

. Private fields (because they’re internal):

    std::string firstName;
    
    std::string lastName;
    
    std::string nickname;
    
    std::string phoneNumber;
    
    std::string darkestSecret;

. Public methods:

    void setInfo(); → Ask the user to input each field
    
    void displayShort(int index);  → Show one-line summary for search
    
    void displayFull(); → Print all 5 fields in full
    
    bool isEmpty() const; → Help to check if the contact is filled

🔹 Step 3: Create Class PhoneBook

. This class stores 8 contacts and manages indexing.

. Private fields:
    Contact contacts[8];
    
    int totalContacts;

. Public methods:

    void addContact(); -> adds a new contact. If totalContacts == 8, overwrite the oldest one (using circular buffer).
    
    void searchContact(); -> display the summary table and ask the user to enter a valid index.
