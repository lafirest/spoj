;;;sbcl自带大数运算
;;;dp[i][j]中i代表(从个位开始数)第几位,j代表0和1,在某位i前面添加一个0,将不会增加数字个数
;;;所以dp[i][0] = dp[i-1][0],而在前面增加一个1则会使之前为0和为1的两部分都生效,所以dp[i][1] = 
;;;dp[i-1][0] + dp[i-1][1]
(defvar limit 10010)
(defvar dp (make-array (list limit 2)))

(defun main ()
  (let ((n (read)))
    (setf (aref dp 0 1) 1)
    (setf (aref dp 0 0) 0)
    (loop
       for i from 1 to n
       do(progn
           (setf (aref dp i 0)
                 (aref dp (1- i) 1))
           (setf (aref dp i 1)
                 (+
                  (aref dp (1- i) 0)
                  (aref dp (1- i) 1)))))
    (format t "~a~%" (+
                      (aref dp n 0)
                      (aref dp n 1)))))

(main)
