--- a/xc/lib/Xaw3d/MultiSrc.c	2006-01-09 08:30:52.000000000 +0100
+++ b/xc/lib/Xaw3d/MultiSrc.c	2008-07-24 11:16:52.000000000 +0200
@@ -739,6 +739,7 @@
   
   if ( string_set || (old_src->multi_src.type != src->multi_src.type) ) {
     RemoveOldStringOrFile(old_src, string_set);
+    src->multi_src.allocated_string = old_src->multi_src.allocated_string;
     file = InitStringOrFile(src, string_set);
 
     /* Load pieces does this logic for us, but it shouldn't.  Its messy.*/
