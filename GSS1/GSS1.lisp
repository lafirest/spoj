;;; 代码是看GSS1.cpp里面的,GSS1.cpp刚好没有超时,这个会tle

;;; 线段树的节点
(defstruct (node (:constructor -make-node))
  (max 0 :type (signed-byte 32))                ;;; 最大值
  (sum 0 :type (signed-byte 32))                ;;; 所有子树的和
  (lmax 0 :type (signed-byte 32))               ;;; 左边的最大值
  (rmax 0 :type (signed-byte 32)))              ;;; 右边的最大值

(defconstant inf -1000000000)

(defun make-node (&optional (initial 0))
  (-make-node :max initial :sum initial :lmax initial :rmax initial))

;;; 通过x y构造父节点
(defun update (x y)
  (let ((curnode (make-node)))
    ;;; 最大值为(max 左节点的最大值 右节点的最大值 (+ 左节点的右边最大值 右节点左边最大值))
    (setf (node-max curnode) (max (+ (node-rmax x) (node-lmax y)) (node-max x) (node-max y)))
    ;;; 和为两个子节点的和的和
    (setf (node-sum curnode) (+ (node-sum x) (node-sum y)))
    ;;; 左边的最大值为(max 左节点的左边最大值 (+ 左节点的和 右节点左边的最大值))
    (setf (node-lmax curnode) (max (node-lmax x) (+ (node-sum x) (node-lmax y))))
    ;;; 同上
    (setf (node-rmax curnode) (max (node-rmax y) (+ (node-sum y) (node-rmax x))))
    curnode))

;;; 构造线段树
(defun build (segTree pos l r)
  (if (= l r)
    (setf (aref segTree pos) (make-node (read)))
    (let ((mid (ash (+ l r) -1))
          (next (* pos 2)))

      ;;; 先构造子树
      (build segTree next l mid)
      (build segTree (1+ next) (1+ mid) r)

      ;;; 回溯构造父节点
      (let ((ln (aref segTree next))
            (rn (aref segTree (1+ next))))
        (setf (aref segTree pos) (update ln rn))))))

;;; 查询
(defun query (segTree pos start end left right)
  (if (<= left start end right) 
    ;;; 查询范围在当前区间内
    (aref segTree pos)
    (let ((x (make-node inf))
          (y (make-node inf))
          (next (* pos 2))
          (mid (ash (+ start end) -1)))
      (setf (node-sum x) 0)
      (setf (node-sum y) 0)
      ;;; 查询的下限小于中间值,则去左子树查找x
      (when (<= left mid)
        (setf x (query segTree next start mid left right)))
      ;;; 查询的上限大于中间值,则去右子树查找y
      (when (< mid right)
        (setf y (query segTree (1+ next) (1+ mid) end left right)))
      (update x y))))

(defun main ()
  (let* ((n (read))
         (segTree (make-array 100000 :element-type 'node :initial-element (make-node))))
    (build segTree 1 1 n)
    (loop repeat (read)
          do (let ((node (query segTree 1 1 n (read) (read))))
               (format t "~A~%" (node-max node))))))

(main)
