;;; 这道题目没有找到比较简单和高效的解法...想了几种方案都不行
;;; 然后就只要采用暴力模拟的方式了

;;; 查找到需要处理的任务,并将其前面的任务放入到队列的尾部
(defun delete-item (item list &optional (acc nil))
  (if (endp list)
      (values -1 nil)
      (let ((head (car list)))
        (if (= (abs head) item)
            (values head (append (cdr list) (reverse acc)))
            (delete-item item (cdr list) (cons head acc))))))

;;; 这里的做法就是,依次从olist里面移除slist的第一个数,也就是当前应该输出的数
;;; 如果被溢出的数是要处理的任务,则返回times+1,如果不是继续处理,直到遇到需要输出的任务
(defun calc-times (olist slist times)
  (let ((ohead (abs (car olist)))
        (shead (car slist)))
    ;;; 下面的两个分支实际逻辑一样,可以合并在一起,只是开始写时没想清除，但相等时直接
    ;;; 处理,不走delete-item也可以提高点效率
    (if (= ohead shead)
        (if (< (car olist) 0)
            (1+ times)
            (calc-times (cdr olist) (cdr slist) (1+ times)))
        (multiple-value-bind (item left) (delete-item shead olist)
          (if (< item 0)
              (1+ times)
              (calc-times left (cdr slist) (1+ times)))))))

(defun main ()
  (loop repeat (read)
     do(let* ((m (read))
              (n (read))
              (olist nil)
              (slist nil))
         ;;; 读入数据,对要处理的任务做标记
         (loop for i from 0 below m
            do(let ((cv (read)))
                (if (= i n)
                    (push (- cv) olist)
                    (push cv olist))
                (push cv slist)))

         ;;; 对slist排序,得到正确的输入顺序
         (setf slist (sort slist #'>))
         (format t "~A~%" (calc-times (reverse olist) slist 0)))))

(main)
