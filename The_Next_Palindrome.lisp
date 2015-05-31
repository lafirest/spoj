;;;WRONG:超时
;;;修改方案:将左边的复制到右边,然后判断原来的左边大于右边则输出,否则进位输出
;;;懒得修改论
(defun check-str (numstr)
  (loop for x across numstr
        when (not (eql x #\9))
        return nil
        finally (return t)))

(defun carry-numstr (numstr mid len)
  (loop for x from mid downto 0
        for y from (if (evenp len) mid (1+ mid)) to len 
        do(let* ((newval (1+ (char-code (aref numstr x))))
                 (new (code-char newval)))
            (cond 
              ((> newval 57)
                (setf (aref numstr x) #\0)
                (setf (aref numstr y) #\0))
              (t 
                (setf (aref numstr x) new)
                (setf (aref numstr y) new)
                (return numstr))))
        finally (return numstr)))

(defun compare-find-next (numstr)
    (let* ((len (1- (length numstr)))
           (mid (floor (/ len 2))))
      (loop for x from 0 to mid
            for y from len downto (1+ mid)
            with eqlcnt = 0 
            do (let ((left (aref numstr x))
                     (right (aref numstr y)))
                 (cond
                   ((char> left right)
                    (setf (aref numstr y) left))
                   ((char< left right)
                    (setf numstr (carry-numstr numstr mid len))
                    (setf (aref numstr y) (aref numstr x)))
                   (t
                    (incf eqlcnt))))
            count 1 into cnt 
            finally (return (if (= cnt eqlcnt) (carry-numstr numstr mid len) numstr)))))

(defun find-next-str (numstr num)
  (if (check-str numstr)
    (+ 2 num)
    (compare-find-next numstr)))

(defun find-next (num)
  (if (< num 9)
    (incf num)
    (find-next-str (write-to-string num) num)))

(dotimes (x (read))
  (format t "~A~%" (find-next (read))))
