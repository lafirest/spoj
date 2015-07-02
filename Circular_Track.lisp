;;; http://www.quora.com/How-do-I-solve-the-problem-SPOJ-SPEED
;;; 首先没太看懂什么意思,看了上面才明白,题目是求两者相遇的点的
;;; 个数(不重复的点)
;;; 推到过程就像上面的,两则经过(lcm ta tb)的时间t1后将重新在起点处
;;; 相遇,假设在这个过程中相遇了n次,则相遇且不重复的点的个数是n个
;;; 因为是匀速运动,所以每次相遇需要消耗时间(/ t1 n) t2,而在圆周上
;;; 的追击问题的要点就是速度快的追上速度慢的,需要多跑一圈,所以t2=
;;; 周长D / 速度差(- va vb),所以n = (lcm ta tb) (/ D (- va vb))
(loop repeat (read)
      do (let ((va (read))
               (vb (read)))
           (format t "~A~%" (/ (abs (- va vb)) (gcd va vb)))))
