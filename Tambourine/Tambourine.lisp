;;; 正多边形外接圆的半径问题,lisp的没有ac,a版本的ac了,应该是精度问题
;;; 这儿估计将结果转换为double-float或许可以ac
(setf *read-default-float-format* 'double-float)

(defun main ()
  (loop
     for r of-type (unsigned-byte 16) = (read)
     for n of-type (unsigned-byte 16) = (read)
     until (= 0 r n)
     do(format t "~,2f~%" (/ r (sin (/ 3.14159265358979 (* 2 n)))))))

(main)
