(defun find-the-number (index)
  (+ (* (1- index) 250) 192))


(dotimes (x (read))
    (format t "~A~%" (find-the-number (read))))
