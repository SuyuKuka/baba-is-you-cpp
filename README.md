# Baba Is You

## About
Baba Is You is a C++ puzzle game developed as a first-year Master's (M1 IMPAIRS) project at Université Paris Cité based on the game BABA IS YOU. Built entirely from scratch in C++, utilizing manual memory management (strictly without smart pointers or auto), custom operator overloading, and an MVC design pattern.

The game features a dynamic rule engine where pushing text blocks alters the physics and properties of the entities in real-time.

Note: As this was originally an academic project evaluated on architectural design, the codebase emphasizes explicit memory handling (allocations/deallocations) and deep copy management. The source code and comment might contains some French.

## Tech Stack
- **Language:** C++ (Standard Library)
- **Graphics:** SFML (Simple and Fast Multimedia Library)
- **Level Design:** JSON parsing for dynamic map loading
- **Build System:** Makefile
- **Architecture:** Model-View-Controller

## Key Features
- **Graphical Interface:** Fully rendered graphical window built with SFML, cleanly separated from the core game logic.
- **Dynamic Rule Engine:** Real-time parsing of text blocks on the grid to update entity properties and game mechanics.
- **JSON Map Parsing:** Dynamic level loading via JSON files, allowing for flexible map design and easy integration of new levels.
- **Advanced Mechanics:** Full support for pushing multiple entities, superpositions, and resolving rule conflicts.
- **Strict Memory Management:** Careful implementation of constructors, destructors, and deep copies to prevent memory leaks without relying on smart pointers.
- **Undo / Redo System:** Seamless ability to revert and replay moves to enhance playability.
- **Extended Features:** Includes additional mechanics such as the PULL action, KEY/DOOR interactions, and complex AND rules.

## Project Structure

```text
📁 baba-is-you
│
├── 📁 docs
│   ├── 🖼️ baba-is-you_uml.png      # UML diagrams
│   └── 📄 technical_report.pdf     # Technical architecture report
|
├── 📁 include/                     # Dependencies
│   ├── 📁 controller/
│   ├── 📁 model/
│   │   ├── 📁 entity/
│   │   ├── 📁 map/
│   │   └── 📁 rule/
│   └── 📁 view/
│
├── 📁 resources/                   # Game assets and level data
│   ├── 📁 fonts/
│   ├── 📁 maps/
│   └── 📁 sprites/
│
└── 📁 src/                         # C++ source files (.cpp)
│   ├── 📁 controller/
│   ├── 📁 model/
│   │   ├── 📁 entity/
│   │   ├── 📁 map/
│   │   └── 📁 rule/
│   └── 📁 view/
│
├── 📄 LICENSE                      # License of the project
├── 📄 Makefile                     # Build configuration
└── 📄 README.md                    # Project documentation
```

## Getting Started

### Prerequisites
- C++ Compiler (GCC/Clang)
- Make
- SFML Library (e.g., `libsfml-dev` on Debian/Ubuntu)
- A Unix terminal

### Installation

1. **Clone the repository:**

```bash
git clone https://github.com/SuyuKuka/baba-is-you-cpp.git baba-is-you
cd baba-is-you    
```

2. **Compile the project:**

```bash
make
```

3. **Launch the game:**

```bash
make run
```

4. **Cleaning**

```bash
make clean
```

## Controls

The game supports **Arrow Keys**, **WASD**, and **ZQSD** for movement:

- **Up:** `W`, `Z`, or `Up Arrow`
- **Left:** `A`, `Q`, or `Left Arrow`
- **Down:** `S` or `Down Arrow`
- **Right:** `D` or `Right Arrow`

**Actions:**
- **CTRL + Direction:** Pull objects (Extended feature)
- **R:** Undo the last move
- **T:** Redo a reverted move
- **Enter:** Reset the current level
- **Escape:** Quit the level

## Team

This project was developed collaboratively as a 2-person team:

- **CHEN Michel** - C++ Development & Game Architecture 
  [![GitHub](https://img.shields.io/badge/GitHub-Profile-181717?logo=github)](https://github.com/SuyuKuka)
  [![LinkedIn](https://img.shields.io/badge/LinkedIn-Profile-0A66C2?logo=linkedin)](https://linkedin.com/in/chen-michel)

- **HUYNH Minh Van Claude** - C++ Development & Game Architecture
  [![GitHub](https://img.shields.io/badge/GitHub-Profile-181717?logo=github)](https://github.com/huynh-claude)

## License

This project is licensed under the GPL 3.0 License — see [LICENSE](LICENSE) for details.
