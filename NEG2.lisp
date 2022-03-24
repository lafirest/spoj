;; https://en.wikipedia.org/wiki/Negative_base#Calculation

(declaim (optimize (speed 3)))

(defvar result (make-string 64))

(defun div (X)
  (multiple-value-bind (a b) (floor x -2)
    (if (>= b 0)
        (values a b)
        (ceiling x -2))))

(defun calc (n i)
  (if (zerop n)
      (reverse
       (subseq result 0 i))
      (multiple-value-bind (a b) (div n)
        (setf (aref result i)
              (if (zerop b)
                  #\0
                  #\1))
        (calc a (1+ i)))))

(let ((i (read)))
  (format t "~A~%"
          (if (zerop i)
              0
              (calc i 0))))
