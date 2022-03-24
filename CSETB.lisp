(declaim (optimize (speed 3)))

(defparameter bitsets (make-array 10001 :element-type 'fixnum))

(defparameter memorization (make-array 10001 :element-type 'fixnum))

(defun getsets (n)
  (if (zerop n)
      0
      (let ((m (aref bitsets n)))
        (if (/= 0 m)
            m
            (let ((mv (1+ (getsets (logand n (1- n))))))
              (setf (aref bitsets n) mv)
              mv)))))

(defun calc (n)
  (if (zerop n)
      0
      (let ((m (aref memorization n)))
        (if (/= 0 m)
            m
            (let ((mv (+ (calc (1- n))
                         (getsets n))))
              (setf (aref memorization n) mv)
              mv)))))

(let ((n (read)))
  (loop repeat n
        do (format t "~D~%" (calc (read)))))
