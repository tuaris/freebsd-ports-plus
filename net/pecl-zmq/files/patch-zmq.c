--- zmq.c.orig	2025-01-22 00:00:00 UTC
+++ zmq.c
@@ -2867,7 +2867,7 @@ PHP_MINIT_FUNCTION(zmq)
 
 	INIT_CLASS_ENTRY(ce_exception, "ZMQException", NULL);
-	php_zmq_exception_sc_entry = zend_register_internal_class_ex(&ce_exception, zend_exception_get_default());
+	php_zmq_exception_sc_entry = zend_register_internal_class_ex(&ce_exception, zend_ce_exception);
 	php_zmq_exception_sc_entry->ce_flags &= ~ZEND_ACC_FINAL;
 
 	INIT_CLASS_ENTRY(ce_context_exception, "ZMQContextException", NULL);
