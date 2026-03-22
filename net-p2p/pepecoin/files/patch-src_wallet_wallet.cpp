--- src/wallet/wallet.cpp.orig	2024-12-16 14:16:07 UTC
+++ src/wallet/wallet.cpp
@@ -2159,6 +2159,7 @@ bool CWallet::SelectCoinsMinConf(const CAmount& nTarge
 {
     setCoinsRet.clear();
     nValueRet = 0;
+    OpenSSLRandomContext ossl_rand;
 
     // List of values less than target
     pair<CAmount, pair<const CWalletTx*,unsigned int> > coinLowestLarger;
@@ -2167,7 +2168,7 @@ bool CWallet::SelectCoinsMinConf(const CAmount& nTarge
     vector<pair<CAmount, pair<const CWalletTx*,unsigned int> > > vValue;
     CAmount nTotalLower = 0;
 
-    random_shuffle(vCoins.begin(), vCoins.end(), GetRandInt);
+    shuffle(vCoins.begin(), vCoins.end(), ossl_rand);
 
     BOOST_FOREACH(const COutput &output, vCoins)
     {
