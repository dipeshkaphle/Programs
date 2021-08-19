#lang racket

(define len 
  (
   lambda (lst)
   (
	match lst
	['() 0]
	[_ (+ 1 (len (cdr lst)))]
	)
   ))

(printf "~a" (len '(1 2 3 4  5 6)))
