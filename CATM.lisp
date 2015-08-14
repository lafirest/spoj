;;; 可以用bfs,做多路搜索,如果最后老鼠无路可走,那么老鼠就死了
;;; 但这道题目没有必要做bfs.只要老鼠在到达边界前,其他两只猫
;;; 不能到达老鼠的脱离点,那么老鼠就活下来了.然后猫和老鼠的速度一样
;;; 所以只需老鼠到4个方向的垂直距离比任何一直猫到该点距离都小,则
;;; 老鼠逃脱
;;; 这道题目错了3次,头两次把行和列搞反了！！！第三次忘记调用main,唉,细节呀
(defun can-pass (n m mn mm cn cm kn km)
  ;;; up
  (when (> 
          (min 
            (+ cn (abs (- mm cm))) 
            (+ kn (abs (- mm km))))
          mn)
    (return-from can-pass t))

  ;;; down 
  (when (> 
          (min
            (+ (- n cn) (abs (- mm cm))) 
            (+ (- n kn) (abs (- mm km))))
          (- n mn))
    (return-from can-pass t))

  ;;; left
  (when (> 
          (min
            (+ cm (abs (- cn mn)))
            (+ km (abs (- kn mn))))
          mm)
    (return-from can-pass t))

  ;;; right
  (when (> 
          (min
            (+ (- m cm) (abs (- cn mn))) 
            (+ (- m km) (abs (- kn mn)))) 
          (- m mm))
    (return-from can-pass t))

  nil)


(defun main ()
  (let ((n (read))
        (m (read))
        (k (read)))
    (declare ((unsigned-byte 8) n m k))
    (loop
      repeat k
      do(let ((mn (read))
              (mm (read))
              (cn (read))
              (cm (read))
              (kn (read))
              (km (read)))
          (declare ((unsigned-byte 8) mn mm cn cm kn km))
          (format t "~a~%" (if (can-pass n m mn mm cn cm kn km) "YES" "NO"))))))

(main)
