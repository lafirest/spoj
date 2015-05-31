;;;换成bitmap会更加节省时间和空间
(defvar hash (make-hash-table :test 'equal))

(defun is-will-stop(n)
  (loop with x = n
        do(cond 
            ((<= x 1)
             (return "TAK"))
            ((gethash x hash nil)
             (return "NIE"))
            (t
             (setf (gethash x hash) t)
             (if (zerop (mod x 2))
               (setf x (floor (/ x 2)))
               (setf x (* 3 (1+ x))))))))

             
(format t "~A~%" (is-will-stop (read)))
