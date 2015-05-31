(defun get-size (n)
  (/ (* pi (expt (/ n pi) 2)) 2))

(loop for len = (read)
      until (zerop len)
      do (format t "~,2F~%" (get-size len)))
