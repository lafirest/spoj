;;; 这个题目有三种解法,这是我的方案开始有个分支写错了,不能ac,所以有了方案二,是githup上的代码
;;; 我的这个解法的思路很原始,这是一个贪心算法适用的问题,所以我在check里面模拟每一步的思考过程
;;; 能选者h小于等于5时只有1种选择,小于等于20时有两种,根据b的值来进行选择,共三种情况.h大于20时,
;;; 上次如果选的不是1就选1,如果是则判断a是否小于等于10,这样就只能选3,否则就选2,尽量贪婪使值最大

;;; 方案二的代码比我的简单很多,而且是迭代实现,我这儿是一步步的来模拟,而他的代码是先选择1,然后在
;;; 做一个选择,当作一个模拟的步骤,本质上就是将我这儿大量重复的分支进行了分支合并,让后将递归转换为迭代

;;; 方案三是dp,从底开始构造dp数组的方法没想过,可行的是用递归进行最大生命值选者,然后用一个数组进行
;;; 记忆化,否则有可能会栈溢出,不过方案二的效率最高了
(defvar pos 0)

(defun check (h a times)
  (when (or (<= h 0)
            (<= a 0))
    (return-from check times))
  (cond 
    ((<= h 5)
     (if (= pos 1)
       times
       (progn 
         (setf pos 1)
         (incf h 3)
         (incf a 2)
         (check h a (1+ times)))))
    ((<= h 20)
     (cond 
       ((<= a 10)
        (if (= pos 1)
          times
          (progn
            (setf pos 1)
            (incf h 3)
            (incf a 2)
            (check h a (1+ times)))))
       ((= pos 1)
        (setf pos 2)
        (incf h -5)
        (incf a -10)
        (check h a (1+ times)))
       (t
         (setf pos 1)
         (incf h 3)
         (incf a 2)
         (check h a (1+ times)))))
    ((= pos 1)
     (cond 
       ((<= a 10)
        (setf pos 3)
        (incf h -20)
        (incf a 5)
        (check h a (1+ times)))
       (t
         (setf pos 2)
         (incf h -5)
         (incf a -10)
         (check h a (1+ times)))))
    (t
      (setf pos 1)
      (incf h 3)
      (incf a 2)
      (check h a (1+ times)))))

(defun get-times (h a)
  (setf pos 0)
  (check h a 0))

(defun main ()
  (loop repeat (read)
        do(format t "~A~%" (get-times (read) (read)))))

(main)
