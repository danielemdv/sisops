#include	"mesg.h"

#define	SHMKEY	((key_t) 7890) /* base value for shmem key */

#define	SEMKEY1	"/semaforo_cliente" /* client semaphore key */
#define	SEMKEY2	"/semaforo_servidor" /* server semaphore key */

#define	PERMS	0666
