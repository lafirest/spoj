(defun calc (n)
  (rem (- (/ (* 3 n (1+ n)) 2) n) 1000007))

(dotimes (x (read))
  (format t "~A~%" (calc (read))))


