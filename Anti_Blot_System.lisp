(defun deal ()
  (let* ((lst (list (read) (read) (read) (read) (read)))
         (n1 (first lst))
         (n2 (third lst))
         (n3 (fifth lst))) 
    (cond 
      ((symbolp n1)
        (format t "~A + ~A = ~A~%" 
              (- n3 n2) n2 n3))
      ((symbolp n2)
        (format t "~A + ~A = ~A~%" 
              n1 (- n3 n1) n3))
      ((symbolp n3)
        (format t "~A + ~A = ~A~%" 
              n1 n2 (+ n1 n2)))
      (t
       (format t "~A + ~A = ~A~%" n1 n2 n3)))))


(dotimes (x (read))
  (deal))

