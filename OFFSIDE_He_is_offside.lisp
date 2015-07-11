;;; 没有越位的条件是进攻方离球门最近的距离,不小于防守方中离
;;; 球门第二近的距离.
(loop for attack = (read)
      for defender = (read)
      until (and (zerop attack) (zerop defender))
      do(let ((minimum (loop repeat attack 
                             with minimum = 10000
                             do(let ((v (read)))
                                 (when (< v minimum)
                                   (setf minimum v)))
                             finally (return minimum)))
              (arr (make-array defender :element-type 'fixnum)))
          (loop for i from 0 below defender
                do(setf (aref arr i) (read)))
          (sort arr #'<)
          (format t "~A~%"
                  (if (< minimum (aref arr 1))
                    "Y"
                    "N"))))

