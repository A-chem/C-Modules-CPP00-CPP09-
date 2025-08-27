# C++ Module 00 – Overview & Guide  

## 📌 Core Concepts (Step-by-Step)

### 🔹 Project & Compile Rules
- Always compile with:
  ```sh
  c++ -Wall -Wextra -Werror -std=c++98
  ```
- Strict naming:
  - Files: follow convention (`UpperCamelCase` for classes).
  - Classes: `UpperCamelCase`.
- No function implementations in headers (except **templates**).
- Add **include guards**; each header must be self-sufficient.

---

### 🔹 What You May / May Not Use
✅ Allowed:  
- C++ standard library (`std::string`, `iostream`, etc.).  

🚫 Forbidden:  
- `printf`, `malloc/free`.  
- External libs (`C++11`, `Boost`, etc.).  
- `using namespace ...`.  
- `friend` (unless explicitly allowed).  
- STL containers/algorithms (until later modules).  

---

### 🔹 Namespaces
- Always reference explicitly:
  ```cpp
  std::cout << "Hello";
  ```
- Never use `using namespace std;`.

---

### 🔹 Classes & Encapsulation
- Design classes with **private data** and **public methods**.  
- Use **real classes** (`PhoneBook`, `Contact`) → no `struct`, no globals.  

---

### 🔹 Member Functions
- Declarations → `.hpp`  
- Definitions → `.cpp`  
- No function bodies in headers (except templates).  

---

### 🔹 Initialization
- Use **constructors** to initialize members.  
- Prefer **initialization lists** for deterministic setup.  

---

### 🔹 `static` & `const` Basics
- `static` → belongs to class, not object.  
- `const` methods → promise not to change object state.  
- `const` data → immutable once set.  

---

### 🔹 Standard I/O Streams
- Use `std::cout` / `std::cin`.  
- Format tables with `<iomanip>` (`std::setw`, right alignment).  

---

### 🔹 Memory Model Awareness
- No leaks.  
- Understand object lifetime.  
- **ex01** → no dynamic allocation allowed.  

---

## 📝 Exercises

### **ex00 – Megaphone**
**Goal:** Print CLI arguments in uppercase.  

Steps:  
1. If no args → print `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.  
2. Concatenate args (or print one by one).  
3. Convert each char → uppercase (`std::toupper`).  
4. Output via `std::cout`.  

---

### **ex01 – My Awesome PhoneBook**
**Goal:** Build a simple CLI phonebook.  

#### Classes
- `Contact`  
  - Private fields: `firstName`, `lastName`, `nickname`, `phoneNumber`, `darkestSecret`.  
- `PhoneBook`  
  - Fixed array of 8 `Contact`s (circular buffer).  

#### Commands
- **ADD** → ask for fields, store in next slot, reject empty input.  
- **SEARCH** →  
  - Print table (index | first | last | nick).  
  - Column width = 10 (truncate long strings → `9 chars + '.'`).  
  - Ask for index, validate, display contact details.  
- **EXIT** → quit, data lost (no persistence).  

#### Constraints
- No dynamic allocation.  
- Encapsulation enforced.  
- Interaction only via methods.  

---

### **ex02 – The Job Of Your Dreams (optional)**
**Goal:** Rebuild `Account.cpp` so tests match the log output.  

Steps:  
1. Read `Account.hpp` → understand API/signatures.  
2. Implement in `Account.cpp` based on behaviors seen in `tests.cpp`.  
3. Compare output with reference log (`timestamps may differ`).  
4. Destructor print order may vary → acceptable.  

⚠️ Not mandatory, but great practice in reverse engineering from headers & tests.  

---

## 🚀 Summary
By the end of **Module 00**, you’ll be comfortable with:  
- Strict compile rules (`-Wall -Wextra -Werror -std=c++98`).  
- Proper header/implementation separation.  
- Encapsulation & class design.  
- Constructors & init lists.  
- `static` / `const` basics.  
- CLI interaction via `std::cin` / `std::cout`.  
- Writing small but complete C++ programs without dynamic allocation.  
