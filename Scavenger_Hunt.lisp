;;;除开头节点和尾节点外，其他节点做为连接节点都会出现两次，而每两个节点一行，
;;;因此总共会读取n - 2 + 1行.
;;;然后每个节点都存入哈希表中,当节点是头次读取时,将其加入hash中.如果是第二次
;;;读取,则说明此节点已经和前后节点联通，此时将其从哈希表中删除。读取时将每个
;;;节点的后续节点设置好。
;;;在所有行数读取完毕后,此时哈希表中只剩下头节点和尾节点两个节点，找到头节点
;;;依次打印出整个链表就可以了。
;;;注意:需要设在common lisp为大小写敏感
(setf (readtable-case *readtable*) :invert)
(defstruct node
  name 
  next)

(defun print-way (node)
  (let ((name (node-name node))
        (next (node-next node)))
    (format t "~A~%" name)
    (when next
      (print-way next))))

(defun find-way (num)
  (if (<= num 1)
    (format t "~A~%" (read-line))
    (let ((nodemap (make-hash-table :test 'equal))
          (times (1+ (- num 2))))
      (dotimes (t1 times)
        (let* ((s (read))
               (e (read))
               (sn (gethash s nodemap nil))
               (en (gethash e nodemap nil)))
          (cond 
            ((and sn en)
             (setf (node-next sn) en)
             (remhash s nodemap)
             (remhash e nodemap))
            (sn
              (let ((cen (make-node :name e :next nil)))
                (setf (node-next sn) cen)
                (setf (gethash e nodemap) cen)
                (remhash s nodemap)))
            (en 
              (setf (gethash s nodemap) 
                    (make-node :name s :next en))
              (remhash e nodemap))
            (t
             (let ((csn (make-node :name s :next nil))
                   (cen (make-node :name e :next nil)))
               (setf (node-next csn) cen)
               (setf (gethash s nodemap) csn)
               (setf (gethash e nodemap) cen))))))
      (loop for v being the hash-value in nodemap 
            when (node-next v)
            do(return (print-way v))))))

(defun test ()
  (dotimes (x (read))
    (format t "Scenario #~A:~%" (1+ x))
    (find-way (read))
    (format t "~%")))

(test)
