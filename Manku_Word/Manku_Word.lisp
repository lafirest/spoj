;;; 进制转换问题
(defvar manku #(#\m #\a #\n #\k #\u))

(defun main ()
  (let ((stream (make-string-output-stream)))
    (loop repeat (read)
       do(let ((x (read)))
           (declare ((unsigned-byte 64) x))
           (loop until (zerop x)
              do(multiple-value-bind (nx mod) (floor x 5)
                  (cond
                    ((zerop mod)
                     (princ #\u stream)
                     (setf x (max 0 (1- nx))))
                    (t
                     (princ (svref manku (1- mod)) stream)
                     (setf x nx)))))
           (format t "~a~%" (reverse (get-output-stream-string stream)))))))

                
