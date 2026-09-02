# 🚌 Bus Reservation System (BRS)

A native desktop GUI application in C, built with **GTK** and **CMake**, developed during my second semester of B.Tech. This project focuses on the fundamentals of native GUI development and build-system setup — GTK layout, event-driven programming, and configuring a full C compilation toolchain from scratch.

---

## 📌 Overview

Most early programming projects run in a terminal with sequential input/output. This one instead sets up a real native desktop application: a windowed GUI built with GTK, compiled through a properly configured CMake build system, using `pkg-config` to resolve library paths on a MinGW-w64/MSYS2 toolchain on Windows.

The current build is a working GUI layout (window, labeled widgets, event loop, and clean shutdown handling) — the reservation/booking logic itself is the next stage of the project, described in the roadmap below.

---

## ✨ What's Working

- Native window creation and event loop using GTK (`gtk_init`, `gtk_main`)
- Event-driven shutdown handling via GTK signals (`g_signal_connect` + callback)
- Widget layout using nested containers (`hbox` / `vbox`)
- A CMake build configuration that locates and links GTK via `pkg-config`
- Linker configuration to suppress the console window on Windows (`WIN32_EXECUTABLE`)

---

## 🗂️ Project Structure

| File | Purpose |
|---|---|
| `main.c` | The working entry point — builds and runs the GTK window and widget layout |
| `main copy.c` | An early draft/skeleton for a later version (incomplete, not part of the current build) |
| `CMakeLists.txt` | Build configuration — locates GTK via `pkg-config` and defines compiler standards |

> **Note:** `main.c` currently uses the GTK2-style API (`gtk_hbox_new`/`gtk_vbox_new`), while `CMakeLists.txt` is configured to link against GTK4. Aligning these to one consistent GTK version is a near-term cleanup item (see Roadmap).

---

## ⚙️ How It Works

```
Startup → GTK Init → Window & Widget Setup → Event Loop → Signal Callback → Clean Exit
```

1. **Startup:** `gtk_init()` registers the app with the OS display manager.
2. **Window Setup:** A window is created, sized, centered, and titled.
3. **Layout:** Labels are arranged using nested `vbox`/`hbox` containers.
4. **Event Loop:** `gtk_main()` runs, waiting for user interaction.
5. **Shutdown:** Closing the window fires a `destroy` signal, calling a callback that exits the loop cleanly.

---

## 🛠️ Built With

- **C** — application logic
- **GTK** — GUI rendering and event handling
- **CMake** — build configuration
- **pkg-config** — library path resolution
- **MSYS2 / MinGW-w64** — compiler toolchain on Windows

---

## 🚀 Getting Started

### Prerequisites
- [MSYS2](https://www.msys2.org/) with the MinGW-w64 toolchain
- GTK development libraries (installed via `pacman`)
- CMake

> The current `CMakeLists.txt` has a hardcoded MSYS2 path (`C:/msys64/...`). If your MSYS2 install lives elsewhere, update that path before building.

### Build with CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### Run
```bash
./BRSgui.exe
```

---

## 📚 What This Project Demonstrates

- Setting up a native C compilation toolchain from scratch (MSYS2/MinGW-w64)
- Using CMake + `pkg-config` to locate and link external libraries, instead of hardcoding paths or relying on an IDE
- Building an event-driven GUI application — window/widget structure and signal-based interaction, rather than sequential terminal I/O
- Reading and writing low-level build configuration (compiler standards, linker flags)

---

## 📄 License

Open for educational and portfolio use — feel free to fork and build on it.
