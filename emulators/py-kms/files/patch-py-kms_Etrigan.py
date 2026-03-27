--- py-kms/Etrigan.py.orig	2022-12-17 00:00:00 UTC
+++ py-kms/Etrigan.py
@@ -409,8 +409,8 @@
 
         def exclude(self, func):
-                from inspect import getargspec
-                args = getargspec(func)
+                from inspect import getfullargspec
+                args = getfullargspec(func)
                 if callable(func):
                         try:
                                 args[0].pop(0)
