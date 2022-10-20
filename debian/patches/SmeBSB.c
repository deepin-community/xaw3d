--- a/xc/lib/Xaw3d/SmeBSB.c	2003-08-04 17:27:58.000000000 +0200
+++ b/xc/lib/Xaw3d/SmeBSB.c	2003-08-07 15:02:39.000000000 +0200
@@ -52,6 +52,8 @@
 #include <X11/Xaw3d/Cardinals.h>
 #include <stdio.h>
 
+#include "XawAlloc.h"
+
 /* needed for abs() */
 #ifndef X_NOT_STDC_ENV
 #include <stdlib.h>
@@ -712,6 +714,8 @@
     int x, y;
     unsigned int width, height, bw;
     char buf[BUFSIZ];
+    char *pbuf;
+    int len;
     
     if (is_left) {
 	width = height = 0;
@@ -720,18 +724,24 @@
 	    if (!XGetGeometry(XtDisplayOfObject(w), 
 			    entry->sme_bsb.left_bitmap, &root, &x, &y,
 			    &width, &height, &bw, &entry->sme_bsb.left_depth)) {
-		(void) sprintf(buf, "Xaw SmeBSB Object: %s %s \"%s\".",
-			"Could not get Left Bitmap",
-			"geometry information for menu entry",
-			XtName(w));
-		XtAppError(XtWidgetToApplicationContext(w), buf);
+               char *err1 = "Xaw SmeBSB Object: Could not get Left Bitmap geometry information for menu entry ";
+	       len = strlen(err1) + strlen(XtName(w)) + 3 + 1;
+               pbuf = XtStackAlloc(len, buf);
+               if (pbuf == NULL) return;
+               sprintf(pbuf, "%s\"%s\".", err1, XtName(w));
+               XtAppError(XtWidgetToApplicationContext(w), pbuf);
+               XtStackFree(pbuf, buf);
 	    }
 #ifdef NEVER
 	    if (entry->sme_bsb.left_depth != 1) {
-		(void) sprintf(buf, "Xaw SmeBSB Object: %s \"%s\" %s.", 
-			"Left Bitmap of entry",  XtName(w),
-			"is not one bit deep");
-		XtAppError(XtWidgetToApplicationContext(w), buf);
+               char *err1 = "Xaw SmeBSB Object: Left Bitmap of entry ";
+               char *err2 = " is not one bit deep.";
+               len = strlen(err1) + strlen(err2) + strlen(XtName(w)) + 2 + 1;
+               pbuf = XtStackAlloc(len, buf);
+               if (pbuf == NULL) return;
+               sprintf(pbuf, "%s\"%s\"%s", err1, XtName(w), err2);
+               XtAppError(XtWidgetToApplicationContext(w), pbuf);
+               XtStackFree(pbuf, buf);
 	    }
 #endif
 	}
@@ -745,18 +755,24 @@
 	    if (!XGetGeometry(XtDisplayOfObject(w),
 			    entry->sme_bsb.right_bitmap, &root, &x, &y,
 			    &width, &height, &bw, &entry->sme_bsb.right_depth)) {
-		(void) sprintf(buf, "Xaw SmeBSB Object: %s %s \"%s\".",
-			"Could not get Right Bitmap",
-			"geometry information for menu entry",
-			XtName(w));
-		XtAppError(XtWidgetToApplicationContext(w), buf);
+            char *err1 = "Xaw SmeBSB Object: Could not get Right Bitmap geometry information for menu entry ";
+            len = strlen(err1) + strlen(XtName(w)) + 3 + 1;
+            pbuf = XtStackAlloc(len, buf);
+            if (pbuf == NULL) return;
+            sprintf(pbuf, "%s\"%s\".", err1, XtName(w));
+            XtAppError(XtWidgetToApplicationContext(w), pbuf);
+            XtStackFree(pbuf, buf);
 	    }
 #ifdef NEVER
 	    if (entry->sme_bsb.right_depth != 1) {
-		(void) sprintf(buf, "Xaw SmeBSB Object: %s \"%s\" %s.", 
-			"Right Bitmap of entry", XtName(w),
-			"is not one bit deep");
-		XtAppError(XtWidgetToApplicationContext(w), buf);
+            char *err1 = "Xaw SmeBSB Object: Right Bitmap of entry ";
+            char *err2 = " is not one bit deep.";
+            len = strlen(err1) + strlen(err2) + strlen(XtName(w)) + 2 + 1;
+            pbuf = XtStackAlloc(len, buf);
+            if (pbuf == NULL) return;
+            sprintf(pbuf, "%s\"%s\"%s", err1, XtName(w), err2);
+            XtAppError(XtWidgetToApplicationContext(w), pbuf);
+            XtStackFree(pbuf, buf);
 	    }
 #endif
 	}
