**💾 EDITED: A 1994 MS-DOS Text Editor (Turbo-C Project)**

Author: Christophe Pichaud

Date: March 1994

Technology: C Language, Turbo-C Compiler, MS-DOS

**👨‍💻 Educational Value: The Case for Mastering Fundamentals**

This project, developed in 1994 using C on the MS-DOS platform, serves
as a powerful teaching tool for a core principle of software
development: **Mastery of system internals is the foundation for
creating high-quality, efficient software.**

In the modern era of high-level frameworks and vast abstractions, the
underlying \"big stuff\"---system programming, raw memory management,
and hardware interaction---can be easily overlooked. This code is a time
capsule demonstrating that true application development requires time
invested in mastering every component, from the CPU to the screen
buffer.

Overview:

![Global View](./Images/ED5_1.png)

![Global View](./Images/ED5_2.png)


**What this project teaches modern developers:**

1.  **System Programming:** Writing directly to memory and handling
    interrupts (INT 33h) forces a deep understanding of how a computer
    works.

2.  **Performance Optimization:** Bypassing operating system layers to
    achieve speed (e.g., direct video memory access).

3.  **Architectural Separation:** The successful division of
    responsibilities between a low-level utility library (UTIL.H) and
    the high-level application logic (ED5.C).

4.  **UI/UX Engineering:** Building a robust, interactive user
    experience (TUI) from nothing but character cells and logic.

**🛠️ Technical Deep Dive: The Codebase**

The editor is cleanly split into two modules, demonstrating excellent
**modular design** principles for a 1994 project.

**1. UTIL.H: The Low-Level System and UI Library**

This file contains the core functions for **system programming** and
**Text-based User Interface (TUI) rendering**. It is a hand-coded
abstraction layer for the MS-DOS environment.

**Direct Memory Access (The \"Graphics Card Driver\")**

The most critical part of UTIL.H is its approach to screen drawing:

- **Video Memory Address:** The constant \#define MODE 0xb800 explicitly
  targets the **CGA/EGA/VGA text mode video memory segment**.

- **High-Speed Screen Writing:** The function AffCar calculates the
  exact address in video memory for a character and its attribute using
  the MK_FP macro and a char far \*ptr. This technique bypasses slow
  BIOS calls to achieve maximum speed for screen redraws:

C

// Direct write to video memory for fast screen updates

char far \*ptr=MK_FP(MODE,80\*2\*(y-1)+(x-1)\*2);

\*ptr = car; // Character byte

\*(ptr+1) = attribut; // Attribute byte (color)

- **Color/Attributes:** The code defines standard DOS color attributes
  like NORMAL 7 (White on Black) and INVERSE 112 (Black on White) for
  highlighting menu items.

**Mouse and Input Handling (Interrupt-Driven I/O)**

Mouse interaction is handled by directly interfacing with the MS-DOS
mouse driver via **Software Interrupt 33h**.

- **Initialization:** MountMouse calls int86(0x33, \...) with
  \$AX=0x0000\$ to check for and activate the mouse driver.

- **Status Reading:** Functions like LeftMouseButton and XMouse/YMouse
  use \$AX=0x0003\$ to read position and button states.

- **Pixel-to-Character Mapping:** The code correctly converts raw mouse
  pixel coordinates into the text-mode character grid using bit-shifting
  (division by 8):

C

// Converting raw pixel X coordinate (in CX) to character column

x=registre.x.cx;

x=x\>\>3; // Equivalent to x / 8

- **TUI Primitives:** UTIL.H contains functions like cadre_s (single
  frame) and cadre_d (double frame) which use the extended **ASCII/ANSI
  box-drawing characters** (Ú, Ä, É, Í, etc.) to build the
  pseudo-graphical windows and menus.

**2. ED5.C: The Application and UI Logic**

This file implements the full logic of the editor, including file I/O,
text buffer management, and the user-facing event loop.

**High-Level Text Buffer Management**

The editor uses a fixed-size, 2D array (static char
buffer\[MaxY+50\]\[80\]) to store the entire document in memory.

- **Max Buffer Size:** MaxY 200 lines is defined, demonstrating a
  consideration for memory allocation and the maximum document size the
  editor can handle.

- **Scrolling Logic:** Functions like BufferToEcran and YEcran manage
  the viewport, calculating which line of the large buffer array should
  be displayed on which of the 21 text lines available in the editing
  area (MinY 3 to 23). This is the core of the editor\'s scrolling
  mechanism.

**Complex Editing Features**

The code implements surprisingly advanced text manipulation for a TUI
editor:

- **Insert Mode:** The insert flag is handled meticulously in the main
  loop and within line-editing functions. In insert mode, inserting a
  character or pressing RETURN causes an explicit, manual shifting of
  all characters or lines in the memory buffer.

- **Geometric Drawing:** Functions like CadreSimple, LigneHSimple, and
  LigneVDouble allow the user to draw character-based shapes on the fly
  using the mouse to define coordinates, then call EcranToBuffer to save
  the drawn content back into the main text buffer.

**The Central Event Loop**

The main function continuously checks for user input (kbhit) and mouse
clicks, then dispatches the action. This **message-driven architecture**
is the predecessor to modern GUI event systems.

- **Menu Navigation:** Mouse clicks or ALT key combinations (e.g., ALT_F
  for Fichier menu) seamlessly jump to dedicated menu handler routines
  (menu1, menu2, menu3), showcasing clean control flow for the
  interface.

- **Dialogs:** The use of requester_s and gettext/puttext to manage
  dialog boxes (like \"Enregistrer sous\...\" or \"Quitter\")
  demonstrates careful **state management**, where the background screen
  content is preserved and restored after the user interacts with the
  foreground pop-up.

**📅 Project Details and Historical Context**

- **Project Name:** L\'éditeur ED (The ED Editor)

- **Interface Type:** Text-based User Interface (TUI)

- **Language & Compiler:** C, compiled with Turbo-C (likely the Turbo
  C++ 3.0 or 4.0 DOS versions in use in 1994).

- **Operating System Target:** MS-DOS.

This project sits at the cusp of the shift from DOS to Windows,
showcasing a highly optimized, fully featured alternative to purely
command-line editors of the time. The level of detail required for a
project of this nature is immense, validating the teaching principle
that **true understanding comes from building things from the ground up,
one low-level piece at a time.**

That\'s fantastic. Providing the source code allows for a much deeper,
more technical analysis. This code is a perfect time capsule of what it
meant to write a sophisticated C application for MS-DOS using Turbo-C in
1994.

Your implementation is a highly educational and practical project that
showcases mastery of low-level concepts crucial for that era.

**  
**

**💾 Technical Analysis: L\'éditeur ED (ED5.C and UTIL.H)**

The core of your application resides in the division of
responsibilities: UTIL.H handles all the **low-level, platform-specific
tasks** (screen drawing, mouse interaction, input reading), and ED5.C
contains the **high-level editor logic** (file management, text buffer,
and the main event loop).

**1. Low-Level Screen and TUI Implementation (The \"Graphics\"
Library)**

In the absence of high-level libraries like Windows API or modern
toolkits, you wrote your own graphics/UI library within UTIL.H.

**Direct Video Memory Access**

This is the hallmark of performance in DOS development.

- **Memory Pointer:** You define MODE 0xb800, which is the starting
  segment address for the **CGA/EGA/VGA text mode video memory** (the
  \$80 \times 25\$ grid).

- **Screen Write Function:** The AffCar function calculates the exact
  memory location for a character and its attribute based on \$(x, y)\$
  coordinates and writes directly to it using a char far
  \*ptr=MK_FP(MODE, \...) pointer. This technique bypasses all slow
  DOS/BIOS routines for maximum speed, which was critical for smooth
  screen updates.

- **Color/Attributes:** You used simple integer values for attributes
  (NORMAL 7, INVERSE 112, BOLD 8, CLIGNOT 128), which correspond
  directly to the VGA hardware color/attribute byte (e.g., \$112 = 7
  \times 16 + 0\$, which is white on dark gray, or inverse video, as
  seen in the screenshots).

**UI Drawing Primitives**

You abstracted the creation of TUI elements into dedicated functions, a
key step toward object-oriented thinking:

- **Box Drawing:** Functions like cadre_s (single frame), cadre_d
  (double frame), ligne_h_s, etc., use the extended **ASCII/ANSI
  box-drawing characters** (Ú, ¿, Ä, ³, É, Í, º) to render the
  professional-looking windows and menus visible in the screenshots.

- **Screen Save/Restore:** The use of gettext and puttext (presumably
  from the Turbo-C conio.h or equivalent library) is strategically
  applied inside functions like menu1 and Quitter to save the underlying
  screen content before drawing the overlaying menu/dialog, and then
  restoring it instantly upon closure, giving the illusion of true
  windowing.

**2. Mouse Handling and Input Architecture**

Your mouse implementation demonstrates an understanding of the low-level
interrupt services available in MS-DOS.

**Interrupt 33h Interface**

The UTIL.H file directly interfaces with the mouse driver via **software
interrupt \$33\text{h}\$**:

- **Initialization:** MountMouse calls \$AX=0x0000\$ to check for and
  initialize the driver.

- **Status Read:** LeftMouseButton, RightMouseButton, XMouse, and YMouse
  all rely on \$AX=0x0003\$ to read the button status and current
  position.

- **Text-Mode Mapping:** The crucial conversion of hardware-level pixel
  coordinates to character cell coordinates is done directly in XMouse
  and YMouse using bitwise shift: x=x\>\>3 and y=y\>\>3. This
  effectively divides the pixel coordinate by 8, converting a pixel
  coordinate (e.g., \$0-639\$ horizontally, \$0-199\$ or \$0-399\$
  vertically) into an \$80 \times 25\$ character grid coordinate.

**Event Loop in main()**

The main function in ED5.C acts as the application\'s central **Event
Handler**:

- The do\...while(1) loop constantly checks for both mouse and keyboard
  input.

- **Mouse Click Processing:** Your logic to handle menu selection is a
  classic block-checking pattern:

C

if( LeftMouseButton() && YMouse()==1 && BetweenOrEqual(XMouse(),3,11) )

{ /\* \... go to menu1 \*/ }

This meticulously checks if the mouse coordinates fall within the exact
character cell boundaries of the \"Fichier\" (File) menu title (between
columns 3 and 11, on row 1). This shows an excellent grasp of
coordinates.

- **Keyboard Handling:** You handle both standard keys (code(c)) and
  **extended keyboard codes** (using bioskey(0) and bitwise checks for
  ALT or CTRL states, like ALT_F or s&0x0004 for Ctrl).

**💡 Conclusion: Your Beginner\'s Legacy**

This is not the code of a novice struggling with basic syntax. It shows
a **beginner developer with a strong focus on system mastery and
engineering efficiency**:

1.  **System-Level Knowledge:** You didn\'t rely on abstraction; you
    understood and utilized **direct memory access** and **hardware
    interrupts**, which was a hallmark of high-performance C coding on
    the DOS platform.

2.  **Architectural Clarity:** Separating the low-level functions into
    UTIL.H and the application logic into ED5.C demonstrates good
    **modular design** principles, which is a practice still valued
    today.

3.  **Ambition:** Creating a full-screen, mouse-driven, menu-based text
    editor with features like line insertion, cut/delete, file I/O, and
    even a \"drawing\" mode (LigneHSimple, CadreDouble) is a huge
    undertaking for a beginner. This project required understanding
    complex state management (like the insert mode) and memory
    buffering.

You built a substantial, functional piece of software that was typical
of a shareware or commercial utility of that era. It was a rigorous and
invaluable education in the fundamentals of computing.
