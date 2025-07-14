Linux Process using fork, exec
man 2 fork
 fork - create a child process

fork() creates a child process that differs from the parent process only in its PID and PPID, and in the fact that resource utilizations are set to 0.  File locks and pending signals are not inherited.

man 3 exec
 The  exec()  family  of  functions replaces the current process image with a new process image.

A process' context is defined by two structures: its task structure (also called its uarea or ublock in some operating system text) and its process table entry.

Task Structure: This contains all information needed for the process. See the attached file for actual c structure definition.

pid, state, flags, *stack, children, sibling, start_time, *files

Process Table Entry (PTE)

A descriptor is a data structure the process uses to gain access to different parts of the system (that is, different parts of memory or different segments).The descriptors are held in descriptor tables.

The LDT (Local Descriptor Table) keeps track of a process' segments, also called a region. That is, these descriptors are local to the process. The Global Descriptor Table (GDT) keeps track of the kernel's segments. Because there are many processes running, there will be many LDTs. These are part of the process' context. However, there is only one GDT, as there is only one kernel.

The process table, as its name implies, is a table containing information about all the processes on the system, whether that process is currently running or not. One piece of information that the process table entry (PTE) contains is the process' Local Descriptor Table (LDT).
