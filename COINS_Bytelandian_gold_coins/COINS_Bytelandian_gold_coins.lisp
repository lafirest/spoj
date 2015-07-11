;;;这道题目使用递归求解,因为n比较大,所以需要进行记忆化,避免反复求
;;;同一个数的解.
;;;这个解不能AC,会得到NEZC(rutime error),原因应该是n(10亿)比较大,分解的值
;;;很多,hash申请的内存超过了可用内存.所以这里应该像C语言版本一样,使用数组
;;;进行记忆化,并且注意申请的内存大小.使用hash进行记忆化成了思维惯式了,需要修改下
(defvar cache (make-hash-table)) 
(defun calc(n)
  (let ((cache-value (gethash n cache)))
    (if cache-value 
      cache-value
      (case n
        (0 0)
        (1 1)
        (2 2)
        (3 3)
        (t 
          (let ((to-cache (max n 
                               (+ (calc (truncate (/ n 2)))
                                  (calc (truncate (/ n 3)))
                                  (calc (truncate (/ n 4)))))))
            (setf (gethash n cache) to-cache)
            to-cache))))))


(loop for n = (read)
      while (integerp n)
      do(format t "~A~%" (calc n)))
