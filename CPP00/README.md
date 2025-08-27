# CPP-Module-00
Core concepts (step-by-step)

Project & compile rules

Use c++ -Wall -Wextra -Werror and keep code valid under -std=c++98.

Follow strict file naming and class naming (UpperCamelCase).

Don’t put function implementations in headers (except templates).

Add include guards; each header must be self-sufficient. 

What you may / may not use

Prefer C++ stdlib (e.g., std::string, iostreams).

Forbidden: printf, malloc/free, external libs (C++11/Boost), using namespace …, friend (unless explicitly allowed).

STL containers/algorithms are off-limits until later modules. 

Namespaces

You’ll reference names with std:: instead of using namespace std; (forbidden here). Keeps the global scope clean. 

Classes & objects + encapsulation

Design classes with private data and public methods (encapsulation).

Instantiate PhoneBook and Contact as real class objects (not structs, not globals). 

Member functions

Put declarations in .hpp and definitions in .cpp (no method bodies in headers, except templates). This enforces separation and correct builds. 

Initialization (constructors / init lists)

Initialize members in constructors; prefer initialization lists for clean, deterministic setup (this habit starts now and matters more in later modules).

static & const basics

static members/funcs belong to the class, not the object (e.g., counters).

const methods promise not to modify object state; const data prevents unintended changes.

Standard I/O streams

Use std::cout/std::cin for printing and reading; format output with <iomanip> (e.g., std::setw, right-alignment). 

Memory model awareness

Avoid leaks; understand object lifetime. (In ex01, you’re told not to use dynamic allocation at all.) 

Apply the concepts per exercise
ex00 — Megaphone

Goal: print all CLI arguments in UPPERCASE; if no args, print the loud noise line.
Steps

Read argv (if argc == 1, print * LOUD AND UNBEARABLE FEEDBACK NOISE *).

Concatenate arguments with spaces (or print one by one).

Convert each char to uppercase and print via std::cout << ... << '\n'.

Keep everything C++-style (no printf). 

ex01 — My Awesome PhoneBook

Goal: tiny CLI phonebook with ADD, SEARCH, EXIT.
Steps

Design classes

class Contact with private fields: first name, last name, nickname, phone number, darkest secret.

class PhoneBook holding a fixed array of 8 Contact objects (no new/vector). Keep a circular index to overwrite the oldest when full. 

ADD

Prompt for each field; reject empty inputs; store in the next slot (wrap at 8). 

SEARCH (table view)

Print a 4-column table: index | first | last | nick.

Each column width = 10, right-aligned; truncate long strings to 9 chars + .. Use <iomanip> helpers. 

Ask for an index; if invalid, handle gracefully; else print all fields (one per line). 

EXIT

Quit; data is ephemeral (no persistence). 

Constraints

No dynamic allocation; keep class data private; interact through methods. 

ex02 — The Job Of Your Dreams (optional)

Goal: rebuild Account.cpp so that tests match the provided log output; you’re given Account.hpp, tests.cpp, and a log file.
Steps

Read Account.hpp to know the exact API and signatures.

Implement every method in Account.cpp to match behaviors inferred from tests.cpp and the log (timestamps will naturally differ).

Expect destructor print order to possibly vary by platform—this is acceptable.

Build with the module rules and confirm your output matches the reference log (except time).

Note: not mandatory to pass Module 00, but great practice for reading headers/tests and re-implementing behavior.
