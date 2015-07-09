;这到题目不难,难的是理解这道题说了什么.这道题目就是求将一个a*b大小的格子拼成一个
;矩形最少需要几个.先l : lcm(a,b),得到的最小公倍数就是最小的那个矩形的长,然后l * l
;求出面积,除以a*b就能得到需要几个,l*l / a * b化简后就是a * b/gcd(a,b)^2
(defun main ()
  (loop for x = (read)
        for y = (read)
        until (= 0 x y)
        do(format t "~A~%" (/ (* x y ) (expt (gcd x y) 2)))))

(main)
