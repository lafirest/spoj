;;; 贪心问题,从最小的开始匹配
;;; 这道题目用红黑树等自排序结构更好,cl原生没有rbtree这类结构,这里用hash和数组来处理,
;;; 数组进行排序,hash进行值到数量的映射 
(defvar map-table (make-hash-table))
(defvar arr (make-array 100 :element-type '(unsigned-byte 32) :initial-element 0))

(defun main ()
  (loop repeat (read)
     do(progn
         (clrhash map-table)
         (let ((n (read))
               (acc 0))
           (declare ((unsigned-byte 8) n))
           (dotimes (times n)
             (incf (gethash (read) map-table 0)))
           (loop
              for pos = 0 then (incf pos)
              for x being each hash-key in map-table
              do(setf (aref arr pos) x))
           (sb-impl::sort-vector arr 0 (1- n) #'< nil)
           (loop
              for x across arr
              do (let* ((value (gethash x map-table 0))
                        (double (* x 2))
                        (dvalue (gethash double map-table 0))
                        (minop (min value dvalue)))
                   (when (not (zerop minop))
                     (decf (gethash x map-table) minop)
                     (decf (gethash double map-table) minop)
                     (incf acc minop))))
           (print acc)))))

(main)




