How do I interpret user needs and implement them into a program? How does creating “user stories” help with this?
I focus on understanding the real problem the user is trying to solve and why it matters. From there, I break their needs into clear and testable requirements. User stories help because they keep the work centered on the user by describing features from their perspective. They make development easier to plan and prioritize.

How do I approach developing programs? What Agile processes do I hope to incorporate into my future development work?
I take an iterative approach to development. I build in small, manageable pieces, gather feedback, and make improvements as I go. I plan to keep using Agile practices like sprint planning, daily check-ins, and backlog refinement. These processes help maintain progress, catch issues early, and improve team communication.

What does it mean to be a good team member in software development?
Being a good team member means being reliable, communicating clearly, and supporting your team. It also means writing clean code, sharing knowledge, asking questions when unsure, and being open to feedback. Good teammates help the team move forward and focus on building solutions that work.

# Corner Grocer (Project Three) — Multi-File Version (B)

Files:
- `main.cpp`
- `PurchaseTracker.h`
- `PurchaseTracker.cpp`
- `CS210_Project_Three_Input_File.txt`

## Build (Mac / Visual Studio Code terminal or VS for Mac terminal)
```
g++ -std=c++17 main.cpp PurchaseTracker.cpp -o grocer
./grocer
```

The program reads `CS210_Project_Three_Input_File.txt` and immediately writes `frequency.dat` as a backup. Use the menu to query an item, print all frequencies, or print a histogram.
