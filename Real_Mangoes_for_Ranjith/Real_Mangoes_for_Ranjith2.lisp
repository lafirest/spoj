;;; 观察版本1中arr中的数就能发现下面的规律
;;; 但是版本1中的数据起始位置是错的,最后两位始终为假,
;;; 所以arr[1]、arr[2]应该都为0,数据应该从arr[3]开始,
;;; 而最开始的公式按照数据从arr[1]开始来写的,结果得到了几个wa
(defun main ()
  (let ((ti (read)))
    (declare ((unsigned-byte 16) ti))
    (loop
      repeat ti
      do(let* ((n (read))
               (v (if (evenp n)
                    (expt (/ (- n 2) 2) 2)  
                    (expt (/ (1- n) 2) 2)))) 
          (declare ((unsigned-byte 32) n)
                   ((unsigned-byte 64) v))
          (format t "~a~%" (mod v n))))))

(main)

