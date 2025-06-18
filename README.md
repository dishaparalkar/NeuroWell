# NeuroWell 🧠💖

**NeuroWell** is a lightweight mental wellness assistant designed to help you track your mood, energy, and focus levels, and analyze your emotional rhythms over time.

---
## 🌟 Features

- Log your mood, energy, and focus levels
- Analyze mood patterns and generate reports
- Clean old logs to avoid clutter
- Hourly mood prompt using Task Scheduler (Windows)
- Structured logs and reports
- Modular design using C & PowerShell
  
---
## 🚀 How to Use
```powershell
cd D:\NeuroWell
```
### 1. **Log Your Mood**

Run this in PowerShell:
in src,
```powershell 
.\mood_logger.exe
```
Note: If it shows error then compile it.
```
gcc mood_logger.c -o mood_logger.exe
```
It asks for:
Mood (1–5)
Energy (1–5)
Focus (1–5)
Result is saved in log/mood_log.txt. 

To View:
```
notepad mood_log.txt
```
---

### 2. **Analyze Mood Patterns**

Run in PowerShell :
in src,
```powershell
.\rhythm_analyzer.exe
```
It analyzes the log and generates a report in log/report.txt.

---
### 3. **Clean Old Logs**
in src,
Run:
```powershell
Clear-Content "D:\NeuroWell\log\mood_log.txt"
```
This will clear your mood_log.txt for a fresh start.

---

### 4. **Automated Hourly Prompt** 
A PowerShell script will auto-run mood_logger.exe hourly.
Run:
```
 script/hourly_prompt.ps1
```
Scheduled via: Windows Task Scheduler

If you want to run manually:
```powershell
.\script\hourly_prompt.ps1
```
---
```
NeuroWell/
├── include/                # Header files
│   ├── idle_tracker.h
│   ├── late_night_watch.h
│   ├── mood_logger.h
│   ├── rhythm_analyzer.h
│   └── utils.h
│
├── src/                    # Source code files (.c)
│   ├── idle_tracker.c
│   ├── late_night_watch.c
│   ├── mood_logger.c
│   ├── rhythm_analyzer.c
│   └── utils.c
│
├── log/                    # Log and report files
│   ├── mood_log.txt
│   ├── report.txt
│   └── weekly_report.txt
│
├── script/                 # Scripts
│   └── hourly_prompt.ps1
│
├── Makefile.txt             # Your Makefile or build instructions
├── .gitignore               # Ignore list for Git
└── README.md                # Project description

```
---
💡 Why NeuroWell?
Your mental well-being matters. NeuroWell provides a tech-assisted way to check in with yourself privately and reflect on your inner state.

---

📅 Future Plans
Export data to CSV or Excel
Add graphs and visualizations
Text-to-speech prompts
GUI with buttons and dark mode

🧑‍💻 Built With
C (Compiled with GCC via MinGW)
PowerShell
Windows Task Scheduler

---

Author
Made with love by Disha ❤

