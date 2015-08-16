;;; 和放奶牛的问题一样,用贪心+二分,不同的是这里二分的对象是浮点数
;;; 这里不能ac,会tle,原因有几点:
;;; 1.面积公式错了,不应该乘以2,导致收缩范围扩大了一倍
;;; 2.函数调用太多,没有写在一起
;;; 3.二分搜索时的精度太高,导致搜索次数很大
(defvar arr (make-array 10001 :element-type 'double-float))

(defun binary-search (start end n f check)
  (loop
    with s = start
    with e = end
    with mid = 0
    while (> (abs (- s e)) 0.0000000001)
    do(progn
        (setf mid (/ (+ s e) 2))
        (if (funcall check mid n f)
          (setf s mid)
          (setf e mid)))
    finally(return (/ s 2))))

(defmacro size (r)
  `(* 2 pi (expt ,r 2)))

(defmacro r (size)
  `(sqrt (/ ,size 2 pi)))

(defun check (size n f)
    (loop
      with pieces = 0
      for i from 0 below n
      do(let ((div (floor (aref arr i) size)))
          (incf pieces div)
          (when (>= pieces f)
            (return-from check t))))
    (return-from check nil)) 

(defun main ()
  (let ((times (read)))
    (declare ((unsigned-byte 32) times))
    (loop
      repeat times
      do(let ((n (read))
              (f (read))
              (sum 0))
          (declare ((unsigned-byte 16) n f))
          (loop
            for i from 0 below n
            do(let ((temp (size (read))))
                (declare (double-float temp))
                (setf (aref arr i) temp)
                (incf sum temp)))
          (format t "~,4f~%" (binary-search 0 (/ sum (1+ f)) n (1+ f) #'check))))))

