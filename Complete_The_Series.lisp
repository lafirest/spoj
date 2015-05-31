;;;超时,同样算法的C++代码ac了...
(defun calc (p3 rp3 sum)
  (let* ((len (/ (* 2 sum) (+ p3 rp3)))
        (inc (/ (- rp3 p3) (- len 5)))
        (start (- p3 (* 2 inc))))
    (format t "~A~%" len)
    (loop for y from 1 to len
          for x = start then (incf x inc)
          do (format t "~A " x)
          finally (format t "~%"))))

(dotimes (x (read))
  (calc (read) (read) (read)))

