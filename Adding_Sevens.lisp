;;; 字符串解析的问题,题目不难,主要是编码麻烦,然后就是0和9对应的字符串要特别注意
;;; 开始0下意识的写成了"000",9没有最下面的那一划,有的话是"117"
(defvar map-list
  '((0 "063")
    (1 "010")
    (2 "093")
    (3 "079")
    (4 "106")
    (5 "103")
    (6 "119")
    (7 "011")
    (8 "127")
    (9 "107")))

(defvar str-num (make-hash-table :test 'equal))
(defvar num-str (make-hash-table))

;;; 将一个list转换为一个数字
(defmacro list-to-num (lst)
  `(loop
     with ratio = 1
     with acc = 0
     for i in ,lst
     do(incf acc (* i ratio))
     do(setf ratio (* ratio 10))
     finally(return acc)))

;;; 将一个数字转换为对应编码的字符串
(defun num-to-str (num)
  (loop
    with result 
    with v = num
    while(> v 0)
    do(push (gethash (mod v 10) num-str) result)
    do(setf v (floor v 10))
    finally(return (apply #'concatenate 'string result))))

;;; 计算输入,并打印输出
(defun calc (args question len)
  (let* ((arg1 (aref args 0))
         (arg2 (aref args 1))
         (num1 (list-to-num arg1))
         (num2 (list-to-num arg2))
         (result (+ num1 num2)))
    (format t "~A~A~%" (subseq question 0 len) (num-to-str result))))

(defun main ()
  ;;; 初始化映射表
  (dolist (x map-list)
    (let ((num (first x))
          (str (second x)))
      (setf (gethash num num-str) str)
      (setf (gethash str str-num) num)))
  (loop
    with question = (make-string 1024)  ;;;输入的缓存
    with buffer = (make-string 3)       ;;;用来取一位数字
    with args = (make-array 2 :element-type 'list :initial-element nil) ;;; 用来存参数
    with lp = 0         ;;; 当前读取的是第几个参数
    with len = 0        ;;; 输入字符串长度
    ;;; 下面比较恶心的是=号后面的处理,因为不清楚是哪种换行方式
    do(block nil
             (loop
               with pos = 0
               do(let ((char (read-char)))
                   (setf (aref question len) char)
                   (incf len)
                   (cond
                     ((char= char #\B)
                      (loop for char = (read-char nil nil 'eof)
                            until (eql char 'eof))
                      (return-from main))
                     ((char= char #\+)
                      (incf lp))
                     ((char= char #\=)
                      (calc args question len)
                      (setf len 0)
                      (setf lp 0)
                      (setf (aref args 0) nil)
                      (setf (aref args 1) nil)
                      (loop 
                        do(let ((next (peek-char)))
                            (if (or
                                  (char< next #\0)
                                  (char> next #\z))
                              (read-char)
                              (loop-finish)))))
                     (t
                       (setf (aref buffer pos) char)
                       (incf pos)
                       (when (= pos 3)
                         (setf pos 0)
                         (push (gethash buffer str-num) (aref args lp))))))))))

(main)
