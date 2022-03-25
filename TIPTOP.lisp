; https://www.wyzant.com/resources/answers/639658/why-perfect-square-has-odd-number-of-factors
(defun win (s r)
  (or (= r (* s s))
      (= r (* (1- s) (1- s)))
      (= r (* (1+ s) (1+ s)))))

(defun main ()
  (let ((case (read)))
    (loop for i from 1 to case
          for x = (read)
          for y = (floor (sqrt x))
          do (format t "Case ~D: ~A~%"
                     i
                     (if (win y x)
                         "Yes"
                         "No")))))

(main)
