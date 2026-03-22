--- build-aux/m4/ax_boost_system.m4.orig	2018-03-04 00:00:00.000000000 +0000
+++ build-aux/m4/ax_boost_system.m4
@@ -108,7 +108,10 @@
 
             fi
             if test "x$ax_lib" = "x"; then
-                AC_MSG_ERROR(Could not find a version of the boost_system library!)
+                dnl Boost >= 1.69 makes boost_system header-only; no library needed
+                AC_MSG_NOTICE([Boost::System appears to be header-only, no library needed])
+                BOOST_SYSTEM_LIB=""
+                AC_SUBST(BOOST_SYSTEM_LIB)
             fi
 			if test "x$link_system" = "xno"; then
 				AC_MSG_ERROR(Could not link against $ax_lib !)
