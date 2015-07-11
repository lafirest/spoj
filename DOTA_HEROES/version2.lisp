;;;这版的想法是排序,然后从大到小计算可以抵挡几次伤害
;;;然后看是否还有剩余
(defun calc (heros tower damage) 
  (cond 
    ((<= tower 0)
     "YES")
    ((endp heros)
     "NO")
    (t
     (let ((hp (car heros)))
       (if (<= hp damage)
         "NO"
         (calc (cdr heros) (- tower (let ((modvalue (mod hp damage)))
                                      (if (zerop modvalue)
                                        (1- (/ hp damage))
                                        (/ (- hp modvalue) damage)))) damage))))))

(loop repeat (read)
      for n = (read)
      for m = (read)
      for d = (read)
      do(progn
          (format t "~A~%" (calc (sort (loop repeat n collect (read)) #'>) m d))
          (read-line)))
              
