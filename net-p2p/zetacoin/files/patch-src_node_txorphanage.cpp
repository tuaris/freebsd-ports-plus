--- src/node/txorphanage.cpp.orig	2026-10-05 00:00:00.000000000 +0000
+++ src/node/txorphanage.cpp	2026-10-05 00:00:00.000000000 +0000
@@ -91,10 +91,10 @@
         }
     };
 
-    struct OrphanIndices final : boost::multi_index::indexed_by<
+    using OrphanIndices = boost::multi_index::indexed_by<
         boost::multi_index::ordered_unique<boost::multi_index::tag<ByWtxid>, WtxidExtractor>,
         boost::multi_index::ordered_unique<boost::multi_index::tag<ByPeer>, ByPeerViewExtractor>
-    >{};
+    >;
 
     using AnnouncementMap = boost::multi_index::multi_index_container<Announcement, OrphanIndices>;
     template<typename Tag>
