# turn-based-survival-game
Turn-based survival simulation game in C++ using OOP concepts. Players manage health, hunger, and energy while exploring, resting, and collecting resources. Includes AI survivors, random events, and inventory system. Built with modular classes, inheritance, and polymorphism for college mini-project.

## 👥 Team Branch Structure

### 🔹 Member 1 – Game Control (member1-game-control)
Files:
- include/Game.h
- src/Game.cpp
- main.cpp

Handles:
- Game loop
- Turn system
- Day counter
- Game over logic

---

### 🔹 Member 2 – Survivor Logic (member2-survivor-logic)
Files:
- include/Survivor.h
- include/HumanSurvivor.h
- include/AISurvivor.h
- src/Survivor.cpp
- src/HumanSurvivor.cpp
- src/AISurvivor.cpp

Handles:
- Player system (OOP)
- Health, hunger, energy
- Player actions

---

### 🔹 Member 3 – Events & UI (member3-events-ui)
Files:
- include/Inventory.h
- include/Event.h
- include/Utils.h
- src/Inventory.cpp
- src/Event.cpp
- src/Utils.cpp

Handles:
- Random events
- Inventory system
- UI display

---

## ⚠️ Rules
- Work only in assigned branch
- Do NOT edit other member files
- Commit and push regularly