(defun calc(girl boy)
  (cond
    ((or (zerop girl) (zerop boy))
     (max girl boy))
    ;;; 均为0的情况在上面处理了
    ((= girl boy)
       1)
    (t
     (let ((max (max girl boy))
           (min (1+ (min girl boy))))
       (if (zerop (rem max min))
         (/ max min)
         (ceiling (/ max min)))))))

(loop for girl = (read)
      for boy = (read)
      until (= -1 girl)
      do (format t "~A~%" (calc girl boy)))


