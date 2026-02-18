--- bin/server.sh.orig	2026-02-04 23:15:38.985377000 -0500
+++ bin/server.sh	2026-02-04 23:15:38.988306000 -0500
@@ -55,7 +55,7 @@
 if [ -f "${JAVA_HOME}/bin/java" ]; then
   JAVA=${JAVA_HOME}/bin/java
 else
-  JAVA=java
+  JAVA=%%JAVA_HOME%%/bin/java
 fi
 
 if [ -z "$ARCADEDB_PID" ]; then
