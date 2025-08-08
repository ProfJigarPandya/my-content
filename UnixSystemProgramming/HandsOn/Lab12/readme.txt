Named semaphore Vs Unnamed semaphore
Named Semaphore: 

semaphores that have a file associated
with them

sem_close()
sem_open()
sem_unlink()

If you look in the man pages, you'll see that a named semaphore is identified by a name, like a System V semaphore, and, similarly, the semaphores have kernel persistence. This implies that these semaphores, like System V, are system-wide and limited to the number that can be active at any one time. The advantage of named semaphores is that they provide synchronization between unrelated process and related process as well as between threads.

Unnamed semaphore:

Again, according to the man pages, an unnamed semaphore is placed in a region of memory that is shared between multiple threads (a thread-shared semaphore) or processes (a process-shared semaphore). A thread-shared semaphore is placed in a region where only threads of an process share them, for example a global variable. A process-shared semaphore is placed in a region where different processes can share them, for example something like a shared memory region. An unnamed semaphore provides synchronization between threads and between related processes and are process-based semaphores.

The unnamed semaphore does not need to use the sem_open call. Instead this one call is replaced by the following two instructions:

{
  sem_t semid;
  int sem_init(sem_t *sem, int pshared, unsigned  value);
}
sem_destroy()
sem_init()

Common API

semctl() sem_getvalue()
semget() sem_post()
semop() sem_timedwait()
sem_trywait()
sem_wait()

The producer consumer problem when solved with two threads, unnamed semaphores are good enough.

If producer and consumer need be different processes, then we have choice of named and unnamed. If named then it can be accessed by related or different processes as file with name of semaphore is in use.

While, we want unnamed semaphore between processes then we have to attach semaphore into some shared memory using shmget and shmat.

Courtesy: http://www.linuxdevcenter.com/pub/a/linux/2007/05/24/semaphores-in-linux.html?page=4
