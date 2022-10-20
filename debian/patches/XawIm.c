--- a/xc/lib/Xaw3d/XawIm.c	1998-04-21 15:42:02.000000000 +0200
+++ b/xc/lib/Xaw3d/XawIm.c	2010-04-26 17:18:24.000000000 +0200
@@ -331,12 +331,12 @@
     /*
      * Close Input Method
      */
-    CloseIM(ve);
     if (!XFindContext(XDisplayOfIM(ve->im.xim), (Window)ve->im.xim, errContext,
 		      (XPointer*)&contextErrData)) {
 	if (contextErrData) XtFree((char *)contextErrData);
     }
     XDeleteContext(XDisplayOfIM(ve->im.xim), (Window)ve->im.xim, errContext);
+    CloseIM(ve);
     ve->im.xim = NULL;
 
     /*
