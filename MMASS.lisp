;;; 解析器
(defun parse-str (str start end)
  (loop with i = start
        with h = 0
        with c = 0
        with o = 0
        while (< i end)
        do(let ((char (char str i)))
            (case char
              ;;; 遇到左括号则进入一个新的解析器,随后更新数据和游标
              (#\( 
               (multiple-value-bind (h2 c2 o2 i2)
                 (parse-str str (1+ i) end)
                 (incf h h2)
                 (incf c c2)
                 (incf o o2)
                 (setf i i2)))
              ;;; 遇到右括号退出当前解析器,并返回数据
              (#\)
               (multiple-value-bind (multi iinc) (check-next str i end)
                 (return-from
                   parse-str
                   (values
                     (* h multi)
                     (* c multi)
                     (* o multi)
                     (+ i 1 iinc)))))
              (t
                ;;; 处理普通字符
                (multiple-value-bind (multi iinc) (check-next str i end)
                  (incf i)
                  (incf i iinc)
                  (case char
                    (#\H
                     (incf h multi))
                    (#\C 
                     (incf c multi))
                    (#\O
                     (incf o multi)))))))
        finally (return (values h c o))))

; 向后看一个字符,确定是否有数字后缀
(defun check-next (str pos end)
  (when (< pos (1- end))
    (let ((next (char str (1+ pos))))
      (when (char<= #\0 next #\9)
        (return-from check-next (values (- (char-code next) 48) 1)))))
  (values 1 0))

(defun main ()
  (let ((str (read-line)))
    (multiple-value-bind 
      (h c o)
      (parse-str str 0 (length str))
      (format t "~a~%" (+ h (* c 12) (* o 16))))))

(main)
