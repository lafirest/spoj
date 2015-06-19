;;; repeat 里面那段可以单独放在一个函数里,这样就可以不用goto语句了
(defun main ()
  (loop for n = (read)
        until (zerop n)
        do (let ((stack nil)
                 (pos 1)
                 (canpass t))
             (loop repeat n
                   if canpass
                   do (let ((value (read)))
                        (tagbody 
                          deal
                          (cond 
                            ;;; 值和位置一直的直接过
                            ((= value pos)
                             (incf pos))
                            ;;; 值比位置小的,不可能重新排成有序的了
                            ((< value pos)
                             (setf canpass nil))
                            ;;; 值比当前位置大分了几种情况
                            ((> value pos)
                             (cond 
                               ;;; 栈为空直接入栈
                               ((null stack)
                                (push value stack))
                               ;;; 栈顶元素和当前需要填充的位置一样
                               ((= (car stack) pos)
                                ;;; 出栈,位置后移
                                (pop stack)
                                (incf pos)
                                ;;; 从栈里面依次弹出和当前填充位置一样的数
                                (dolist (x stack)
                                  (cond 
                                    ((= x pos)
                                     (pop stack)
                                     (incf pos))
                                    (t 
                                      (return))))
                                ;;; 栈处理完了,但是当前读取的值还没有处理,返回开头进行处理
                                (go deal))
                               ;;; 新入栈的必须比栈顶小,否则就不可能重排为有序序列了
                               ((> (car stack) value)
                                (push value stack))
                               (t 
                                 ;;; 走到这儿说明不能重排为有序的了
                                 (setf canpass nil)))))))
                   else 
                   do (read))
             (format t "~A~%" (if canpass "yes" "no")))))

(main)
