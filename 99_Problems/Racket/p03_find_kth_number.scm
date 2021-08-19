#lang racket

(define element-at 
  (
   lambda (k lst)
   (
	match k
	[0 (car lst)]
	[_ (element-at (sub1 k) (cdr lst))]
	)
   ))


(printf "~a" (element-at 3 '(1 2 3 4 5 6) ))
