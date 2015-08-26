;;; gcd 问题
(defun main ()
  (loop
    for n of-type (unsigned-byte 16) = (read)
    until (zerop n)
    do(let ((acc 0)
            (gcdv 0))
        (declare ((unsigned-byte 16) gcdv)
                 ((unsigned-byte 64) acc))
        (loop
          repeat n
          do(let ((w (read))
                  (h (read))
                  (d (read)))
              (declare ((unsigned-byte 16) w h d))
              (if (zerop gcdv)
                (setf gcdv (gcd w h d))
                (setf gcdv (gcd w h d gcdv)))
              (incf acc (* w h d))))
        (format t "~a~%" (/ acc (expt gcdv 3))))))

(main)
