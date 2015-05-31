;;; 这里的思路是用hash计数,然后排序输出,但是内存消耗较大,AC不过
;;; 用C++代码使用map AC通过
(defvar hash (make-hash-table :test 'equal))
(defun mark-and-sort (num)
  (clrhash hash)
  (dotimes (_ num)
    (incf (gethash (read-line) hash 0)))
  (sort (loop for x being the hash-key in hash
              for y being the hash-value in hash
              collect (list x y))
        #'(lambda(l r) (string< (first l) (first r)))))

(dotimes (_ (read))
  (format t "~{~{~a ~a~}~%~}" (mark-and-sort (read)))
  (format t "~%")
  (read-line))

