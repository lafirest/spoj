;;;只有唯一一个数字不重复,其他数字都会出现两次,
;;;所以用异或的自反性能得到唯一不重复的数
;;;用lisp 始终超时,用C++刚好
(defun calc (cnt r)
  (declare (optimize (speed 3) (safety 0) (debug 0))
           (type fixnum cnt)
           (type integer r))
  (if (zerop cnt)
    r
    (calc (the fixnum (1- cnt)) (the integer (logxor (the integer (read)) r)))))

(format t "~A~%" (calc (read) 0))
