;;; 立方体的总体积为sum := n * m * k,用手每次只能撕下来一块,所以用手需要sum - 1次
;;; 对于用刀切开,我的想法是每次都会将体积分半,所以ceiling(log2(sum))即可,然后这种做
;;; 法对于所有test都对,但就是不能ac
;;; 另外一种做法就是,分别计算将n m k拆分为1需要的次数,和log2不同的是,如果obj是个偶数,
;;; 则直接除以2,如果是个奇数需要+1(也就是上取整,估计就是这儿导致了用log2(sum)会得到wa),
;;; 最后n m k都等于1了,那累计的拆分次数就是用刀切需要的次数
(defmacro calc-times (o)
  `(loop 
     while(> ,o 1)
     do(if (evenp ,o)
         (setf ,o (floor ,o 2))
         (setf ,o (1+ (floor ,o 2))))
     do(incf v)))

(defun main ()
  (let ((ti (read)))
    (declare ((unsigned-byte 16) ti))
    (loop
      for i from 1 to ti
      do(let* ((n (read))
               (m (read))
               (k (read))
               (sum (* n m k))
               (v 0))
          (declare ((unsigned-byte 16) n m k)
                   ((unsigned-byte 64) v))
          (calc-times n)
          (calc-times m)
          (calc-times k)
          (format t "Case #~a: ~a ~a~%" i (- sum 1) v)))))

(main)

