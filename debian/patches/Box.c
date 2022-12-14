--- a/xc/lib/Xaw3d/Box.c	1996-10-15 16:41:18.000000000 +0200
+++ b/xc/lib/Xaw3d/Box.c	2007-04-24 15:28:39.000000000 +0200
@@ -353,8 +353,16 @@
 	else {
 	    width = preferred_width;
 	    do { /* find some width big enough to stay within this height */
+#if 0 
 		width *= 2;
 		if (width > constraint->width) width = constraint->width;
+#endif
+                if (width > constraint->width/2) {  /* avoid short int overflow */
+ 		    width = constraint->width;
+		}
+                else { 
+		    width *= 2; 
+		}
 		DoLayout(w, width, 0, &preferred_width, &preferred_height, FALSE);
 	    } while (preferred_height > constraint->height &&
 		     width < constraint->width);
