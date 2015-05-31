;;;代码和The_last_digit.lisp是一样的...
(defun last-digit(a b)
  (case a
    (0 0)
    (1 1)
    (2 
     (case (rem b 4)
       (0 6)
       (1 2)
       (2 4)
       (3 8)))
    (3
     (case (rem b 4)
       (0 1)
       (1 3)
       (2 9)
       (3 7)))
    (4 
     (case (rem b 2)
       (1 4)
       (0 6)))
    (5 5)
    (6 6)
    (7 
     (case (rem b 4)
       (0 1)
       (1 7)
       (2 9)
       (3 3)))
    (8
     (case (rem b 4)
       (0 6)
       (1 8)
       (2 4)
       (3 2)))
    (9
     (case (rem b 2)
       (0 1)
       (1 9)))))

(defun glast-digit (a b)
  (if (zerop a)
    0
    (if (zerop b)
      1
      (last-digit (rem a 10) b))))

(dotimes (x (read))
  (format t "~A~%" (glast-digit (read) (read))))

