;;; 用log不能ac为什么???

;;; 求第一个大于/等于n的2的x次方数(对n取log,然后在expt会wa,搞不懂)
(defun power (n)
  (loop 
    with i = 1
    while (< i n)
    do(setf i (ash i 1))
    finally (return (- i n))))

(defun main ()
  (loop
    do(let ((G (read))
            (T1 (read))
            (A (read))
            (D (read)))
        (declare ((signed-byte 32) G T1 A D))
        (when (= -1 G)
          (loop-finish))
        (let*  ((kt (+ (* G A))) ;;; 出线人数
                (at (* G (floor (* T1 (1- T1)) 2))) ;;; 需要进行的比赛次数(两两一场,和本组里面每个队伍打一场)
                (kta (+ kt D))   ;;; 实际出线人数
                (ni (power kta)))
          ;;; 通过小组赛的两两一场,如有16队,则需要比赛8、4、2、1场,等于x-1
          (if (zerop ni)
            (format t "~a*~a/~a+~a=~a+0~%" G A T1 D (+ at kta -1)) ;;; 刚好是2的x次方则不用增加队伍
            (format t "~a*~a/~a+~a=~a+~a~%" G A T1 D (+ at kta ni -1) ni)))))) ;;; 添加队伍

(main)
