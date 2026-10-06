--- src/node/miner.h.orig	2026-10-05 00:00:00.000000000 +0000
+++ src/node/miner.h	2026-10-05 00:00:00.000000000 +0000
@@ -109,7 +109,7 @@
 };
 
 
-struct CTxMemPoolModifiedEntry_Indices final : boost::multi_index::indexed_by<
+using CTxMemPoolModifiedEntry_Indices = boost::multi_index::indexed_by<
     boost::multi_index::ordered_unique<
         modifiedentry_iter,
         CompareCTxMemPoolIter
@@ -121,8 +121,7 @@
         boost::multi_index::identity<CTxMemPoolModifiedEntry>,
         CompareTxMemPoolEntryByAncestorFee
     >
->
-{};
+>;
 
 typedef boost::multi_index_container<
     CTxMemPoolModifiedEntry,
