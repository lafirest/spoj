;;; 这个版本是按照规则进行筛选,因为数据范围从2～1亿,所以毫无疑问会tle,
;;; 但运行后发现了arr数组中的数是很有规律的,所以便有了版本2(ac)
;(defconstant max-range 100000000)
(defconstant max-range 100)

(defvar arr (make-array (1+ max-range) :element-type '(unsigned-byte 32) :initial-element 0))

(defun main ()
  (setf (aref arr 1) 1)
  (loop
    with i = 1
    while(<= i (- max-range 2))
    do(let ((i2 (1+ i))
            (i3 (+ i 2)))
        (setf (aref arr i) (aref arr (1- i)))
        (cond
          ((/= 1 (gcd i i2))
           (incf i))
          ((/= 1 (gcd i i3))
           (incf i))
          ((/= 1 (gcd i2 i3))
           (incf i)
           (setf (aref arr i) (aref arr (1- i)))
           (incf i))
          (t
            (incf (aref arr i) i)
            (incf i)))))
  (setf (aref arr (1- max-range)) (aref arr (- max-range 2)))
  (setf (aref arr max-range) (aref arr (1- max-range)))
  (let ((ti (read)))
    (declare ((unsigned-byte 16) ti))
    (loop
      repeat ti
      do(let ((n (read)))
          (declare ((unsigned-byte 32) n))
          (format t "~a~%" (mod (aref arr n) n))))))

(main)

