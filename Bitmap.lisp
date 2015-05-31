;;;WRONG:超时
;;;BFS,熟悉BFS后重新做
;;;http://www.spoj.com/problems/BITMAP/
(defun calc (x y wl)
  (apply #'min (mapcar #'(lambda (pair) 
                           (+ (abs (- x (first pair)))
                              (abs (- y (second pair))))) wl)))

(defun get-array()
  (let* ((x (read))
         (y (read))
         (wl '())
         (arr (make-array (list x y) :initial-element 0)))
    (dotimes (posx x)
      (let ((str (read-line)))
        (loop for e across str 
              count 1 into posy
              if (char= e #\1)
              do(progn
                  (setf (aref arr posx (1- posy)) 1)
                  (push (list posx (1- posy)) wl)))))
    (loop for posx from 0 below x
          do (loop for posy from 0 below y
                   do (format t "~A "
                              (if (= 1 (aref arr posx posy))
                                0
                                (calc posx posy wl)))
                   finally (format t "~%")))))

(dotimes (_ (read))
  (get-array)
  (read-line))
