(loop repeat (read)
      for x = (read)
      when (> x 0)
        sum x into y
      finally (print y))
