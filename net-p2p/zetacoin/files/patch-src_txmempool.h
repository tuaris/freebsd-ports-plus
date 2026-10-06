--- src/txmempool.h.orig	2026-10-05 00:00:00.000000000 +0000
+++ src/txmempool.h	2026-10-05 00:00:00.000000000 +0000
@@ -306,7 +306,7 @@
 
     static const int ROLLING_FEE_HALFLIFE = 60 * 60 * 12; // public only for testing
 
-    struct CTxMemPoolEntry_Indices final : boost::multi_index::indexed_by<
+    using CTxMemPoolEntry_Indices = boost::multi_index::indexed_by<
             // sorted by txid
             boost::multi_index::hashed_unique<mempoolentry_txid, SaltedTxidHasher>,
             // sorted by wtxid
@@ -333,8 +333,7 @@
                 boost::multi_index::identity<CTxMemPoolEntry>,
                 CompareTxMemPoolEntryByAncestorFee
             >
-        >
-        {};
+        >;
     typedef boost::multi_index_container<
         CTxMemPoolEntry,
         CTxMemPoolEntry_Indices
