# Student Billing System

Description
-----------
Simple student billing system (project repo description: "desc"). This repository contains both a command-line implementation (C) and a browser-based GUI (HTML) for managing student billing data, plus a sample data file and a project members spreadsheet.

Repository structure
--------------------
- CMD/
  - [student_billing.c](https://github.com/Ekisa02/COMP-415-GROUP-PROJECT-Student-Billing-System-/blob/main/CMD/student_billing.c) — C source code for the command-line billing application.
  - [billing_system](https://github.com/Ekisa02/COMP-415-GROUP-PROJECT-Student-Billing-System-/blob/main/CMD/billing_system) — Compiled binary / executable (size suggests a binary).
  - [student_billing.dat](https://github.com/Ekisa02/COMP-415-GROUP-PROJECT-Student-Billing-System-/blob/main/CMD/student_billing.dat) — Sample data file used by the command-line program.
- GUI/
  - [index.html](https://github.com/Ekisa02/COMP-415-GROUP-PROJECT-Student-Billing-System-/blob/main/GUI/index.html) — Browser UI for the billing system.
- Comp415 (HCI)  Group members list.xlsx — Project members list / spreadsheet.

Key features (assumptions based on filenames)
---------------------------------------------
- Command-line student billing management implemented in C.
- Persistent sample data provided (student_billing.dat).
- A GUI front-end implemented as a static HTML page (likely interacts with local data or demonstrates UI).
- Team spreadsheet with group members and roles.

Requirements
------------
- For the command-line app:
  - GCC (or another C compiler) or the included binary for your platform.
  - A POSIX-like environment for building/running the code on *nix systems. If you use Windows, use MinGW or WSL.
- For the GUI:
  - Any modern web browser (Chrome, Firefox, Edge, Safari).

Build & run (command-line)
--------------------------
1. Build from source (if you want to recompile):
   - Linux / macOS:
     ```
     gcc -o CMD/billing_system CMD/student_billing.c
     ```
   - Windows (MinGW):
     ```
     gcc -o CMD\\billing_system.exe CMD\\student_billing.c
     ```
   Adjust the command if the source requires additional flags or libraries.

2. Run the compiled binary:
   - Linux / macOS:
     ```
     ./CMD/billing_system
     ```
   - Windows:
     ```
     CMD\billing_system.exe
     ```

3. If the program expects the sample data file, ensure `CMD/student_billing.dat` is present in the working directory or in the location the program expects:
   ```
   cp CMD/student_billing.dat .
   ./CMD/billing_system
   ```

GUI (web)
---------
- Open the GUI in your browser:
  - Double-click `GUI/index.html` or open it from the browser: `file:///.../GUI/index.html`
- If the GUI requires a local webserver (for features like AJAX or fetch), run a simple static server:
  - Python 3:
    ```
    cd GUI
    python -m http.server 8000
    ```
    Then go to `http://localhost:8000` in your browser.

Data format
-----------
- The repository contains `CMD/student_billing.dat`. I could not read its contents programmatically during my inspection; it may be a plain text, CSV, or binary file. Open it to verify the format and update this README with the exact schema (fields, data types, delimiters). Example checks:
  - `file CMD/student_billing.dat`
  - `head -n 20 CMD/student_billing.dat` (if it's text)
  - `xxd CMD/student_billing.dat | head` (if binary)

Suggested README additions after source inspection
------------------------------------------------
- Detailed build flags and dependencies discovered from `student_billing.c`.
- Usage examples and CLI option descriptions, extracted from program help or comments.
- Screenshots (or an animated GIF) of the GUI and example outputs from the CLI.
- Data schema (columns, types), sample records, and import/export instructions.
- Tests / test data and instructions to run them.
- If the binary is platform-specific, mark its target platform and provide build instructions for others.

Contributing
------------
Contributions are welcome. Suggested workflow:
1. Fork the repository.
2. Create a branch: `git checkout -b feature/my-feature`
3. Commit changes: `git commit -m "Add ..."`
4. Push and open a pull request.

Please include:
- A short description of the change.
- How to reproduce or test the change.
- Any backward-incompatible changes or migration steps.

License
-------
Add a license file (e.g., MIT, Apache-2.0) if you want others to reuse code. Currently no license file was found in the repository listing; without a license, reuse is restricted.

Acknowledgements & Contacts
---------------------------
- Project: Student Billing System
- Maintainer: Repository owner (see repo page)
- For questions or access to file contents, open an issue in the repository or mention @Ekisa02.

Notes about my inspection
-------------------------
- I listed the repository contents and saw CMD and GUI directories, a sample data file, and an Excel group-members file.
- I attempted to read file contents but the read attempts returned failures, so the README contains conservative, accurate instructions based on filenames and common C/HTML project practices.
- If you want a more detailed README (including function descriptions, flags, exact build commands, and screenshots), allow me to open:
  - `CMD/student_billing.c`
  - `GUI/index.html`
  - `CMD/student_billing.dat`
  and I will update the README with concrete details extracted from those files.

What's next (I can do now)
--------------------------
- Fetch the contents of specific files you point to (or let me fetch `CMD/student_billing.c` and `GUI/index.html`) and update the README with precise build/run instructions, command-line arguments, data schema, and examples.
- Add a LICENSE file or a CONTRIBUTING.md if you want templates.
