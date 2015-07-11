;;; 因为1能被所有数整除,所以只要第一个选手选择1就能获胜,所以最优的情况下,
;;; 获胜的始终是第一个玩家
(loop repeat (read)
      do(progn
          (read)
          (format t "~A wins.~%" (if (zerop (read)) "Airborne" "Pagfloyd"))))
