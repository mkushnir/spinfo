#ifndef MNSPINFO_PRIVATE_H_DEFINED
#define MNSPINFO_PRIVATE_H_DEFINED

#include <unistd.h>

#ifdef __FreeBSD__
#include "mnspinfo_freebsd.h"
#endif

#ifdef __linux__
#include "mnspinfo_linux.h"
#endif

#define TIMESPEC_TO_NSEC(ts) ((ts).tv_sec * 1000000000 + (ts).tv_nsec)
#define TIMEVAL_TO_USEC(ts) ((ts).tv_sec * 1000000 + (ts).tv_usec)

#define TICKS_TO_TIMEVAL(tv, mod, ticks)               \
do {                                                   \
    (tv).tv_sec = (ticks) / mod;                       \
    (tv).tv_usec = ((ticks) % mod) * 1000000 / mod;    \
} while (0)                                            \


#ifdef __cplusplus
extern "C" {
#endif

/*
 * platform independent private interface
 */

int mnspinfo_init(mnspinfo_ctx_t *, pid_t, unsigned);
int mnspinfo_update0(mnspinfo_ctx_t *);
int mnspinfo_update1(mnspinfo_ctx_t *);
int mnspinfo_update2(mnspinfo_ctx_t *);
int mnspinfo_update3(mnspinfo_ctx_t *);
int mnspinfo_update4(mnspinfo_ctx_t *);
void mnspinfo_fini(mnspinfo_ctx_t *);

#ifdef __cplusplus
}
#endif

#include <mnspinfo.h>
#endif /* MNSPINFO_PRIVATE_H_DEFINED */
