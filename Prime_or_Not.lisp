;;; 基于概率的质数检测算法
;;; https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
;;; http://www.cnblogs.com/skyivben/archive/2010/07/10/1775001.html
;;; 虽然AC了,但完全没理解,完全就是把上面那个blog的C代码改写了下
;;; 发现自己的数学水平越来越难以应付这些问题了
(defvar k 6)
(defvar strarr #("NO" "YES"))

(defun modmultiply (a b m)
  (mod (* a b) m))

(defun modpow (a b m)
  (let ((value 1))
    (loop with p = (mod a m)
          while (> b 0)
          when (oddp b)
          do (setf value (modmultiply value p m))
          do(setf b (ash b -1))
          do(setf p (modmultiply p p m)))
    value))

(defun mrcheck (a num)
  (let* ((n1 (1- num))
         (s2 (logand n1 (- n1)))
         (x (modpow a (floor (/ n1 s2)) num)))
    (when (or (= x 1) (= x n1))
      (return-from mrcheck nil))
    (loop while(> s2 1)
          do (progn 
               (setf x (modmultiply x x num))
               (when (= x 1)
                 (return-from mrcheck t))
               (when (= x n1)
                 (return-from mrcheck nil)))
          do (setf s2 (ash s2 -1)))
    t))

(defun isprime(num)
  (if (< num 2)
    0
    (if (= num 2)
      1 
      (if (evenp num)
        0
        (loop repeat k
              do(let ((a (+ 2 (random (- num 2)))))
                  (when (mrcheck a num)
                    (return-from isprime 0)))
              finally (return 1))))))

(defun main ()
  (loop repeat (read)
        do(format t "~A~%" (svref strarr (isprime (read))))))

(main)
