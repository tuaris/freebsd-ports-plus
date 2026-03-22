--- src/compat/endian.h.orig	2024-12-16 14:16:07.000000000 +0000
+++ src/compat/endian.h
@@ -14,8 +14,10 @@
 #include "compat/byteswap.h"
 
 #if defined(HAVE_ENDIAN_H)
 #include <endian.h>
-#elif defined(HAVE_SYS_ENDIAN_H)
+#endif
+
+#if defined(HAVE_SYS_ENDIAN_H)
 #include <sys/endian.h>
 #endif
 
@@ -191,7 +193,7 @@
 }
 #endif // HAVE_DECL_LE64TOH
 
-#if HAVE_DECL_BE32DEC == 0
+#if HAVE_DECL_BE32DEC == 0 && !defined(HAVE_SYS_ENDIAN_H)
 static inline uint32_t be32dec(const void *pp)
 {
 	const uint8_t *p = (uint8_t const *)pp;
@@ -200,7 +202,7 @@
 }
 #endif // HAVE_DECL_BE32DEC
 
-#if HAVE_DECL_BE32ENC == 0
+#if HAVE_DECL_BE32ENC == 0 && !defined(HAVE_SYS_ENDIAN_H)
 static inline void be32enc(void *pp, uint32_t x)
 {
 	uint8_t *p = (uint8_t *)pp;
