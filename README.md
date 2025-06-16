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

### 1. **Log Your Mood**

Run this in PowerShell:

```powershell 
.\mood_logger.exe
```

It asks for:
Mood (1–5)
Energy (1–5)
Focus (1–5)
Result is saved in mood_log.txt.

---

### 2. **Analyze Mood Patterns**

Run in PowerShell :

```powershell
.\rhythm_analyzer.exe
```
It analyzes the log and generates a report in log/report.txt.

---
### 3. **Clean Old Logs**

Run:
```powershell
.\clean_log.exe
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
Made with love by Disha ❤️

