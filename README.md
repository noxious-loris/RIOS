# RIOS: Real-Time Operating System for Embedded Systems

## 📌 Overview
RIOS (Real-Time Interrupt Operating System) is a lightweight real-time operating system designed for embedded systems running on microcontrollers like Arduino, ESP8266, and Raspberry Pi.

## ⚙️ Features
- **Task Scheduling**: Allows adding tasks with periodic execution.
- **Task Completion & Garbage Collection**: Removes completed tasks dynamically.
- **Low Latency**: Designed for real-time applications.
- **Interrupt Handling Support**: Handles external interrupts for event-driven tasks.

## 🚀 Setup & Compilation
### **1️⃣ Install Dependencies**
#### Using PlatformIO (Recommended)
```sh
pip install platformio
```
#### Using Arduino IDE
- Install necessary board libraries (ESP8266, STM32, etc.).
- Add `Unity` test framework for unit testing.

### **2️⃣ Build & Run on PlatformIO**
```sh
platformio run
```

### **3️⃣ Compile & Run Tests**
```sh
gcc rios.cpp test_rios.c Unity/src/unity.c -o test_rios && ./test_rios
```

## 📜 API Usage
### **Task Management**
```cpp
void RIOS_AddTask(void (*taskFunc)(), unsigned long period);
void RIOS_MarkTaskCompleted(void (*taskFunc)());
void RIOS_GarbageCollect();
void Rios_Run();
```
### **Example Code**
```cpp
#include "rios.h"

void TaskA() { Serial.println("Task A Running"); }
void TaskB() { Serial.println("Task B Running"); }

void setup() {
    Serial.begin(115200);
    RIOS_AddTask(TaskA, 1000);
    RIOS_AddTask(TaskB, 500);
}

void loop() {
    Rios_Run();
}
```

## 🧪 Unit Tests
Tests are written using the **Unity** framework and validate:
- Task Scheduling Order
- Task Execution Frequency
- Garbage Collection
- System Clock Accuracy
- Interrupt Handling
- Power Failure & Recovery

Run tests using:
```sh
./test_rios
```

## 🛠️ Future Improvements
- Multi-threading support
- Dynamic memory allocation
- Power-saving features

## 📜 License
MIT License. Free to use and modify.

