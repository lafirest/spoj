(defun find-need-count (need lst)
  (let ((sortlst (sort lst #'>)))
    (loop for x in sortlst
          with sum = need 
          until (<= sum 0)
          count x into count
          do(setf sum (- sum x))
          finally (return (if (> sum 0) "impossible" count)))))
          
(defun get-list (col)
  (loop for x from 1 to col 
        collect (read) into lst
        finally (return lst)))

(dotimes (x (read))
  (format t "Scenario #~A:~%" (1+ x))
  (format t "~A~%~%" (find-need-count (read) (get-list (read)))))
