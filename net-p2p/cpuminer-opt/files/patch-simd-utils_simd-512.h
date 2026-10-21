clang requires the _mm512_shuffle_i64x2 selector to be an immediate, which an
inline function parameter is not. Use a macro so AVX-512 builds compile.

--- simd-utils/simd-512.h.orig
+++ simd-utils/simd-512.h
@@ -107,10 +107,10 @@
 #define v512_64(i64)    _mm512_set1_epi64(i64)
 #define v512_32(i32)    _mm512_set1_epi32(i32)

-// A simple 128 bit permute, using function instead of macro avoids
-// problems if the v arg passed as an expression.
-static inline __m512i mm512_perm128( const __m512i v, const int c )
-{  return _mm512_shuffle_i64x2( v, v, c ); }
+// A simple 128 bit permute. The selector must be an immediate, so this is a
+// macro; the statement expression evaluates v once.
+#define mm512_perm128( v, c ) \
+({ const __m512i v_ = (v); _mm512_shuffle_i64x2( v_, v_, c ); })

 // Broadcast 128 bit vector to all lanes of 512 bit vector.
 #define mm512_bcast128( v )    mm512_perm128( _mm512_castsi128_si512( v ), 0 )
