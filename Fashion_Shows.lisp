(defun sum-mul-list (lst1 lst2)
  (loop for x in lst1
        for y in lst2
        sum (* x y) into sum
        finally (return sum)))

(defun get-list (col)
  (loop for x from 1 to col
        collect (read) into lst
        finally (return (sort lst #'>))))

(dotimes (x (read))
  (let ((col (read)))
    (format t "~A~%" (sum-mul-list (get-list col) (get-list col)))))
