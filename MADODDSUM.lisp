(let* ((f (read))
       (l (read))
       (f (if (oddp f) f (1+ f)))
       (l (if (oddp l) l (1- l))))
  (format t "~D~%" (/ (* (+ l f) (+ (- l f) 2)) 4)))
