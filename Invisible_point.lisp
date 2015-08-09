;;; 按照对角线切割,然后找规律 
(defun main ()
  (loop repeat (read)
     do (format t "~A~%" (1+ (ceiling (log (read) 2))))))

(main)
