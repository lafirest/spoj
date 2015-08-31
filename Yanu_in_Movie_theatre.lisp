(defun main ()
  (loop
    for n of-type (unsigned-byte 32) = (read)
    for m of-type (unsigned-byte 32) = (read)
    until (= 0 n m)
    if(zerop n)
    do (format t "1.000000~%")
    else if (> n m)
    do(format t "0.000000~%")
    else
    do(format t "~,6f~%" (/ (- m n -1.0) (+ m 1.0)))))

(main)
