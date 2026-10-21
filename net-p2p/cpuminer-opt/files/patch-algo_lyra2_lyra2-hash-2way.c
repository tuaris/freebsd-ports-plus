Including compat.h ahead of miner.h lets <sys/param.h> replace compat.h's
_ALIGN(x) attribute macro with the FreeBSD pointer-rounding _ALIGN(p).
miner.h includes compat.h after the system headers.

--- algo/lyra2/lyra2-hash-2way.c.orig
+++ algo/lyra2/lyra2-hash-2way.c
@@ -22,7 +22,6 @@
 #include <string.h>
 #include <time.h>
 //#include <mm_malloc.h>
-#include "compat.h"
 #include "miner.h"
 #include "lyra2.h"
 #include "sponge.h"
