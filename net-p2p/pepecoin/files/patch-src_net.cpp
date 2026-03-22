--- src/net.cpp.orig	2024-12-16 14:16:07 UTC
+++ src/net.cpp
@@ -1491,7 +1491,11 @@ void ThreadMapPort()
     struct IGDdatas data;
     int r;
 
+#if MINIUPNPC_API_VERSION >= 18
+    r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr), NULL, 0);
+#else
     r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));
+#endif
     if (r == 1)
     {
         if (fDiscover) {
