(defun isAp (a b c)
  (let ((x (- b a))
        (y (- c b)))
  (values (= x y) x)))

(loop for x = (read)
      for y = (read)
      for z = (read)
      until (= x y z 0)
      do(multiple-value-bind (Ap R) (isAp x y z)
          (if Ap 
            (format t "AP ~A~%" (+ z R))
            (format t "GP ~A~%" (* z (/ z y))))))
