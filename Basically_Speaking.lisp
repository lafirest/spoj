;;; 进制转换问题,因为common lisp自带读写、输出时的进制控制,所以用cl比较简单
(defun main ()
  (loop
    for data = (read nil nil 'eof)  ;;; 以10进制读取
    until(eql data 'eof)
    do(let* ((datastr (format nil "~a" data))   
             ;;;注意:这里不能用write-to-string,因为write-to-string会把一个不能被当前进制(10)解析的数字,当作字符串,
             ;;;导致后面read-from-string读取的是一个符号
             (src (read))
             (dest (read))  ;;; 以10进制方式读取进制
             (*read-base* src)
             (*print-base* dest)    ;;; 设置进制
             (value (read-from-string datastr)) 
             (valuestr (format nil "~a" value))) ;;; 读取并转换
        ;;; 输出
        (if (> (length valuestr) 7)
          (format t "ERROR~%")
          (format t "~a~%" valuestr)))))

;;; 这道题目用C来写也不难,只是麻烦,设src := m, dest := n
;;; value := s[0] * m^0 + s[0] * m^1 + s[n-1] * m^(n-1)
;;; 然后用value和n碾转相除,得到输出进制的倒序,对输出倒序后输出即可

(main)

