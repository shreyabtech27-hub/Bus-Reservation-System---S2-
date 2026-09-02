# 🚌 Bus Reservation System (BRS)

A cross-platform desktop application for managing bus ticket bookings and seat allocations, built with **C/C++** and **GTK** for the graphical interface, using **CMake** as the build system.

---

## 📌 Overview

The Bus Reservation System is a native desktop GUI application that allows users to manage transportation bookings through a clean, responsive interface — rather than a traditional command-line prompt. It was built to explore low-level systems programming, GUI event handling, and modular build automation on Windows using the MSYS2/MinGW-w64 toolchain.

---

## ✨ Features

- Native graphical interface built with **GTK**
- Event-driven architecture (asynchronous UI updates, not linear script execution)
- Clean window layout using nested container widgets (`hbox` / `vbox`)
- Graceful application shutdown with proper memory cleanup
- Cross-environment build support (CMake-based, with a manual compiler fallback)

---

## 🗂️ Project Structure

| File | Purpose |
|---|---|
| `main.c` | Core application entry point — initializes the GTK window, builds the widget layout tree, and runs the main event loop |
| `main copy.c` | Backup/legacy version using GTK3-compatible macros for older system support |
| `CMakeLists.txt` | Build configuration — locates GTK libraries via PkgConfig and defines compiler standards |
| `g++ -std=c++11 -O2 -Wall programName.cpp` | A one-line manual fallback compile command for quick builds without CMake |

---

## ⚙️ How It Works

```
System Boot → GTK Initialization → Layout Tree Packing → Event Listening Loop → Callback Trigger → Safe Exit
```

1. **Startup:** The app initializes GTK (`gtk_init`), which registers the program with the OS display manager.
2. **Window Setup:** A parent window is created, sized, centered on screen, and titled.
3. **Layout Construction:** UI elements (labels) are arranged inside nested `vbox`/`hbox` containers to form the visual layout.
4. **Event Loop:** The app enters `gtk_main()`, an idle listening state that waits for user interaction (clicks, hovers, etc.).
5. **Shutdown:** Closing the window triggers a signal that safely deallocates memory and exits cleanly.

---

## 🛠️ Built With

- **C / C++** — core application logic
- **GTK** — GUI rendering and event handling
- **CMake** — automated build configuration
- **PkgConfig** — library path resolution
- **MSYS2 / MinGW-w64** — POSIX-compatible build environment on Windows

---

## 🚀 Getting Started

### Prerequisites
- [MSYS2](https://www.msys2.org/) installed with the MinGW-w64 toolchain
- GTK development libraries installed via `pacman`
- CMake

### Build with CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Manual Build (fallback)
```bash
g++ -std=c++11 -O2 -Wall programName.cpp -o programName.exe
```

### Run
```bash
./BRSgui.exe
```

---

## 📚 What This Project Demonstrates

- Configuring and troubleshooting a native compilation toolchain from scratch
- Structuring event-driven, asynchronous application logic
- Working with hierarchical UI layout systems
- Using industry-standard build automation tools (CMake) instead of manual, one-off compilation

---

## 📄 License

This project is open for educational and portfolio use. Feel free to fork and build on it.
