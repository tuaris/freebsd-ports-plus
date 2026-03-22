--- src/net_processing.cpp.orig	2024-12-16 14:16:07 UTC
+++ src/net_processing.cpp
@@ -43,7 +43,7 @@ std::atomic<int64_t> nTimeBestReceived(0); // Used onl
 struct IteratorComparator
 {
     template<typename I>
-    bool operator()(const I& a, const I& b)
+    bool operator()(const I& a, const I& b) const
     {
         return &(*a) < &(*b);
     }
@@ -1644,7 +1644,8 @@ bool static ProcessMessage(CNode* pfrom, const std::st
 
         // Randomize entries before processing, to prevent an attacker to
         // determine which entries will make it through the rate limit
-        random_shuffle(vAddr.begin(), vAddr.end(), GetRandInt);
+        OpenSSLRandomContext ossl_rand;
+        shuffle(vAddr.begin(), vAddr.end(), ossl_rand);
 
         BOOST_FOREACH(CAddress& addr, vAddr)
         {
