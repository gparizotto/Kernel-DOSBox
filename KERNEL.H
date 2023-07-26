#include <system.h>

#define MAX_PROCESS_NAME 30
#define INTERRUPT 8

typedef struct bcp
{
    char name[MAX_PROCESS_NAME];
    enum
    {
        activated,
        blocked,
        finished
    } state;
    PTR_DESC context;
    struct bcp *semaphoreQueue;
    struct bcp *next_bcp;
} BCP;

typedef BCP *PTR_BCP;

typedef struct
{
    int value;
    PTR_BCP blocked_queue;
} SEMAPHORE;

extern void far backToDOS();

extern void far startProcessQueue();

extern void far createProcess(void far (*process_address)(), char process_name[MAX_PROCESS_NAME]);

extern void far endProcess();

extern PTR_BCP getNextActiveProcess();

extern void far scheduler();

extern void far activeScheduler();

extern void far initSemaphore(SEMAPHORE *user_semaphore, int semaphore_size);

extern void far downSemaphore(SEMAPHORE *user_semaphore);

extern void far upSemaphore(SEMAPHORE *user_semaphore);
