;;; 这到题目和前面的博弈类型的题目类似,最开始想到的是第一个使下一个变为质数的将获胜利.
;;; 但是质数可以除以1,所以这在想法是错的.任何数都能整除1,从1开始推到便能发现f(n) = !f(n-1),
;;; 而当n==1时,游戏结束.所以游戏就简化为了奇偶判断了...想明白了就发现简直简单的坑爹
(defun main ()
  (loop repeat (read)
     do(format t "~A~%"
               (if (evenp (read))
                   "Thankyou Shaktiman"
                   "Sorry Shaktiman"))))
(main)
