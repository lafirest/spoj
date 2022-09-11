(defparameter maxn 10100)
(defparameter k 14)
(defparameter lg (make-array (1+ maxn)))
(defparameter st (make-array (list maxn (1+ k))))
(defstruct price index value)

(loop for i from 2 to maxn do
  (setf (aref lg i)
        (1+ (aref lg (floor i 2)))))

(defun safe-read () (read t nil 'eof))

(defun min-price (a b)
  (if (< (price-value a) (price-value b))
      a
      b))

(defun init-table (n)
  (loop for i from 0 below n do
    (setf (aref st i 0)
          (make-price :index i :value (read))))

  (loop for j from 1 to (aref lg n)
        do (loop for i from 0
                 while (<= (+ i (ash 1 j)) n)
                 do (setf (aref st i j)
                          (min-price
                           (aref st i (1- j))
                           (aref st (+ i (ash 1 (1- j))) (1- j)))))))

(defun query (lt rt)
  (let* ((l (1- lt))
         (r (1- rt))
         (j (aref lg (1+ (- r l)))))
    (min-price
     (aref st l j)
     (aref st (- r (ash 1 j) -1) j))))

(defun calc (n h b e)
  (let ((res (make-array n)))
    (loop for i from n downto 1
          do (let ((l (max (- i h -1) 1))
                   (r i))
               (incf (aref res (price-index (query l r))))))
    (loop for i from (1- b) to (1- e)
          do (format t "~a~t" (aref res i)))))

(loop as n = (safe-read)
      while (numberp n)
      do (let ((h (read))
               (b (read))
               (e (read)))
           (init-table n)
           (calc n h b e)))
