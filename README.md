
# MyOS - A Simple Operating System

This repository contains the source code for **MyOS**, a minimal operating system written in C and assembly. The project is designed to be bootable and can run on QEMU for testing. It includes basic components like a bootloader, kernel, and a GRUB configuration file.

## Directory Structure

The project has the following structure:

```
/MyOS
│
├── boot.s              # Assembly bootloader
├── grub.cfg            # GRUB configuration file
├── kernel.c            # C kernel code
├── kernel.h            # Kernel header file
├── linker.ld           # Linker script
└── run.sh              # Script for building the OS
```

## Prerequisites

Before building and running **MyOS**, you need to have the following software installed on your system:

- **GCC** (GNU Compiler Collection) for compiling C code
- **GNU Assembler** for compiling assembly code
- **GNU LD** (GNU Linker) for creating the final executable
- **GRUB tools** (for creating a bootable ISO)
- **QEMU** (for running the operating system in a virtual environment)

### Installing Required Tools

If you're using **Ubuntu** or a similar Linux distribution, you can install the necessary packages with the following command:

```bash
sudo apt-get update
sudo apt-get install build-essential qemu grub2 grub-pc-bin grub2-common
```

If you're on **macOS**, you can use **Homebrew** to install the required tools:

```bash
brew install gcc qemu grub
```

For **Windows**, you can install the following:
- **MinGW** or **MSYS2** for GCC and GNU tools
- **QEMU** (via official installer or using Chocolatey)

Once the required tools are installed, you can proceed with building **MyOS**.

## Building the Operating System

To build **MyOS**, follow these steps:

### 1. Assemble the Bootloader

Use the **GNU assembler** to compile the `boot.s` assembly file into an object file:

```bash
as --32 boot.s -o boot.o
```

### 2. Compile the Kernel

Next, compile the `kernel.c` file with **GCC**. The `-m32` flag ensures that it compiles for 32-bit architecture, and other flags ensure the kernel is freestanding (no OS libraries):

```bash
gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
```

### 3. Link the Kernel and Bootloader

After compiling the bootloader and kernel, use **GNU LD** to link them together into a single executable (`MyOS.bin`):

```bash
ld -m elf_i386 -T linker.ld kernel.o boot.o -o MyOS.bin -nostdlib
```

### 4. Verify the Executable with GRUB

Check that the generated `MyOS.bin` file is compatible with GRUB’s multiboot standard:

```bash
grub-file --is-x86-multiboot MyOS.bin
```

### 5. Prepare the Bootable ISO

Now, create the directory structure required for the ISO image and copy the necessary files:

```bash
mkdir -p isodir/boot/grub
cp MyOS.bin isodir/boot/MyOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
```

Then, use **GRUB** to generate a bootable ISO image:

```bash
grub-mkrescue -o MyOS.iso isodir
```

### 6. Run the OS in QEMU

Finally, run the **MyOS** operating system in a virtual machine using **QEMU**:

```bash
qemu-system-x86_64 -cdrom MyOS.iso
```

This command will boot the system from the ISO file in QEMU, allowing you to test and interact with your newly created operating system.

## Running the Operating System

You can run **MyOS** in QEMU using the following command:

```bash
qemu-system-x86_64 -cdrom MyOS.iso
```

This will start the operating system in a virtual machine, which you can interact with. If you wish to make changes or improvements to the operating system, modify the source code, rebuild it, and test it again.



