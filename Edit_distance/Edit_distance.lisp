;;http://en.wikipedia.org/wiki/Levenshtein_distance
;;自己写的lisp和c实现都不能ac,想不通!!!!!!!!!
(defvar dp (make-array '(3001 3001) :element-type 'fixnum :initial-element 0))
(defun LevenshteinDistance (x y)
  (let* ((lenx (1+ (length x)))
         (leny (1+ (length y))))

    ;;; 初始化第一列(字符串x)
    (loop for i from 1 below lenx
          do (setf (aref dp i 0) i))

    ;;; 初始化第一行(字符串y)
    (loop for j from 1 below leny 
          do (setf (aref dp 0 j) j))

    (loop for j from 1 below leny
          do (loop for i from 1 below lenx 
                   if (char= (aref y (1- j)) (aref x (1- i)))
                   do (setf (aref dp i j) (aref dp (1- i) (1- j)))
                   else 
                   do (setf (aref dp i j)
                            (1+ 
                             (min 
                               (aref dp (1- i) j)
                               (aref dp i (1- j))
                               (aref dp (1- i) (1- j)))))))

    (aref dp (1- lenx) (1- leny))))

(loop repeat (read)
      do (format t "~A~%" (LevenshteinDistance (read-line) (read-line))))
