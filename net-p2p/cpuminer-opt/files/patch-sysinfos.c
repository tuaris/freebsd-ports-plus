--- sysinfos.c.orig	2024-01-01 00:00:00.000000000 +0000
+++ sysinfos.c
@@ -17,7 +17,7 @@
 #include "simd-utils.h"
 
 // hwcap.h missing on MinGW, MacOS
-#if defined(__aarch64__) && !(defined(WIN32) || defined(__APPLE__)) 
+#if defined(__aarch64__) && !(defined(WIN32) || defined(__APPLE__) || defined(__FreeBSD__)) 
 #define ARM_AUXV 
 #endif
