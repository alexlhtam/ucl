# Memory & The C Compiler


## Memory
- RAM: random access memory
    - stores running code and data (OS/applications)
- ROM: read only memory
    - non-volatile
    - stores code and data needed to boot machine (BIOS, firmware)
- EEPROM: erasable programmable read only memory
    - non-volatile but can be erased and rewritten
    - updatable firmware
- flash memory
    - non-volatile but can be rewritten many times and easily
    - limited number of rewrites
    - relatively quick
- cache memory
    - multi-level
    - relatively expensive, limited memory
    - reduces access time
    - need to reload on context changes, thread/process switch

## Buses
- control
    - interrupts, read/write signals, status, enable/disable
- address
    - memory address to read/write data
- data 
    - carry data to/from CPU, memory and devices

- address/data bus widths (number of bits) determine how much memory can be addressed and max size of data that can be transferred in one read/write cycle

## Object Files
- called `.o` files on Unix, `.obj` on 
- will contain relocatable binary code
    - specific virtual memory addresses not resolved until linking
    - does not require fixed memory addresses
- processor and OS specific
    - source code needs to be recompiled for different systems

## Linking
- join all the .o and library files into a single executable program
- the addresses of all functions, non-local variables are resolved
    - identified and "linked up"

- every variable and function must be defined once
    - static, disjoint scopes taken into account
    - sometimes the order of linking libraries matters

## Dynamic Linking
- all current Unix, Windows implementations use dynamic linking
- linking done at runtime as functions in libraries are called
    - avoids need to include the libraries in every executable program file

## Libraries
- contains pre-compiled but not fully linked code
- intended to be reusable
- .a files are static linked libraries, not shared, each program gets a copy
- .so or .dll files are dynamically linked libraries
- Unix libraries are named `lib<name>.so` or `.a`
    - libc: core functionality such as malloc, free, printf, string functions, always linked
    - libm: maths functions (-lm on cmd line)