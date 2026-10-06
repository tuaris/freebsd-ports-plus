--- src/txrequest.cpp.orig	2026-10-05 00:00:00.000000000 +0000
+++ src/txrequest.cpp	2026-10-05 00:00:00.000000000 +0000
@@ -208,12 +208,11 @@
     }
 };
 
-struct Announcement_Indices final : boost::multi_index::indexed_by<
+using Announcement_Indices = boost::multi_index::indexed_by<
     boost::multi_index::ordered_unique<boost::multi_index::tag<ByPeer>, ByPeerViewExtractor>,
     boost::multi_index::ordered_non_unique<boost::multi_index::tag<ByTxHash>, ByTxHashViewExtractor>,
     boost::multi_index::ordered_non_unique<boost::multi_index::tag<ByTime>, ByTimeViewExtractor>
->
-{};
+>;
 
 /** Data type for the main data structure (Announcement objects with ByPeer/ByTxHash/ByTime indexes). */
 using Index = boost::multi_index_container<
