;;;这个tle
(defun main ()
  (let ((c (read)))
    (declare ((unsigned-byte 8) c))
    (loop
      repeat c
      do(let ((n (read))
              (sum 0))
          (declare ((unsigned-byte 32) sum)
                   (fixnum n))
          (loop
            repeat n
            do(incf sum (read)))
          (format t "~a~%" (if (zerop (mod sum n))
                             n
                             (1- n)))))))

(main)
