;;; Sparse Table TLE
(declaim (optimize (speed 0) (safety 3)))

(defstruct ext max min)

(defun set-ext (a b)
  (make-ext :max (max (ext-max a) (ext-max b))
            :min (min (ext-min a) (ext-min b))))

(defun init-ext (a)
  (make-ext :max a :min a))

(defun query (st l r)
  (let* ((j (floor (log (- r l -1) 2)))
         (a (aref st l j))
         (b (aref st (- r (ash 1 j) -1) j)))
    (- (max (ext-max a) (ext-max b))
       (min (ext-min a) (ext-min b)))))

(defun calc (n)
  (let* ((k (ceiling (log n 2)))
         (st (make-array (list (1+ n) (1+ k))))
         (result 0))

    (dotimes (i n)
      (setf (aref st i 0) (init-ext (read))))

    (loop for j from 1 to k
          do (loop for i from 0
                   while (<= (+ i (ash 1 j)) n)
                   do (setf (aref st i j)
                            (set-ext
                             (aref st i (1- j))
                             (aref st (+ i (ash 1 (1- j))) (1- j))))))

    (loop for i from 0 below n
          do(loop for j from (1+ i) below n
                  do(incf result (query st i j))))

    (format t "~a~%" result)))

(calc (read))
