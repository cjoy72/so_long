# 🎮 so_long

A smooth, top-down 2D mini game built in C using **MLX42** and **GLFW**. Collect all items, avoid wall collisions, and reach the exit in as few moves as possible!

---

## ✨ Features

- 🖥️ **X11 & Wayland Support**: Native cross-platform display server support powered by MLX42 (OpenGL + GLFW).
- 🧩 **Directional Movement**: Dynamic player sprites updating based on movement direction (Up, Down, Left, Right).
- 🗺️ **Strict Map Parsing & Validation**:
  - Validates map boundary walls.
  - Ensures a valid path to all collectibles and the exit using a **flood-fill** algorithm.
  - Checks rectangularity and required map components (`1`, `0`, `P`, `C`, `E`).
- 🏃 **Real-time Move Counter**: Tracks and displays move counts in the terminal console.
- 🔓 **Dynamic Exit Unlocking**: The exit gate visually unlocks only after all collectibles (`C`) are gathered.

---

## 🕹️ Controls

| Action | Primary Key | Alternative Key |
| :--- | :---: | :---: |
| **Move Up** | <kbd>W</kbd> | <kbd>↑</kbd> |
| **Move Down** | <kbd>S</kbd> | <kbd>↓</kbd> |
| **Move Left** | <kbd>A</kbd> | <kbd>←</kbd> |
| **Move Right** | <kbd>D</kbd> | <kbd>→</kbd> |
| **Exit Game** | <kbd>ESC</kbd> | Window `X` Button |

---

## 🛠️ Prerequisites

Ensure the following dependencies are installed on your Linux system:

- **GCC** / Clang
- **Make**
- **CMake** (required to build MLX42)
- **GLFW3** (`libglfw3-dev` on Debian/Ubuntu, `glfw` on Arch Linux)
- **OpenGL** development libraries

---

## 🚀 Quick Start

### ⚡ One-Liner (Play & Clean Up Automatically)

Execute this single command to build the game, run `maps/test.ber`, and **automatically clean up all compiled binaries/object files upon closing**:

```bash
./play.sh; make fclean
```

*(Alternatively: `./play.sh --clean`)*

---

### Standard Execution Options

#### Option 1: Run with `play.sh`
```bash
./play.sh
```

#### Option 2: Manual Build & Run
```bash
make
./so_long maps/test.ber
```

---

## 🗺️ Map Format (`.ber`)

Maps must be saved as `.ber` files and adhere to the following rules:

| Tile Character | Description |
| :---: | :--- |
| `1` | **Wall** (Impassable border/obstacle) |
| `0` | **Empty Space** (Walkable floor tile) |
| `P` | **Player Starting Position** (Must be exactly 1) |
| `C` | **Collectible** (Must have at least 1) |
| `E` | **Exit** (Must have exactly 1) |

### Example Map (`maps/test.ber`):

```text
1111111111111
1000000000001
1011000001101
1000000000001
1000000000001
1000000000001
1000000000001
1010000000101
1001000001001
1000100010001
1000010100001
100000E000001
1000000000001
1000000000001
1000000000001
100000C000001
100000P000001
1111111111111
```

---

## 💻 Compilation Commands

| Command | Description |
| :--- | :--- |
| `make` | Compiles `MLX42` static library and builds `./so_long` |
| `make clean` | Removes object files (`.o`) |
| `make fclean` | Removes object files, binaries, and `MLX42` build directory |
| `make re` | Performs `fclean` followed by `make` |
| `make leaks` | Runs Valgrind leak checking on `./so_long maps/test.ber` |

---

## 📜 License

Created as part of the 42 School curriculum.
