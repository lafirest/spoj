;;;这道题目并不关心受到伤害的顺序,只要能够抵挡伤害的次数
;;;超过塔数就可以了.所以这里只需要计算所有英雄能够抵挡的
;;;次数和,然后和塔数比较
;;;还有优化点:当lives>=m时,就可以不用计算hp可以抵挡的次数了
;;;注意:判断条件时>=,而不是>,因为lives加的次数都是不会导致
;;;英雄死亡的,所以lives=m时,通过了所有塔,切不会有英雄死亡
(loop repeat (read)
      for n = (read)
      for m = (read)
      for d = (read)
      do(progn
          (format t "~A~%"
                  (loop repeat n
                        with lives = 0
                        do (setf lives
                                 (+ 
                                   lives
                                   (let* ((hp (read))
                                          (modvalue (mod hp d)))
                                     (if (zerop modvalue)
                                       (1- (/ hp d))
                                       (/ (- hp modvalue) d)))))
                        finally (return (if (>= lives m)
                                          "YES"
                                          "NO"))))
          ))
