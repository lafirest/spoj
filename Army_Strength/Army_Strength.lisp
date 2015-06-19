;;; 这个会超时,估计和io相关
(declaim (optimize (speed 2)))
(defun main ()
  (loop repeat (read)
        do (let ((NG (read))
                 (NM (read))
                 (GMax 0)
                 (MMax 0))
             (declare (type fixnum NG NM GMax MMax))
             (if (= 0 NG NM)
               (format t "~A~%" "uncertain")
               (progn 
                 (loop repeat NG
                       do (let ((v (read)))
                            (when (> v GMax)
                              (setf GMax v))))

                 (loop repeat NM 
                       do (let ((v (read)))
                            (when (> v MMax)
                              (setf MMax v))))

                 (format t "~A~%" (if (>= GMax MMax) "Godzilla" "MechaGodzilla")))))))

(main)

