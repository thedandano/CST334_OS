# Lab 6 Instructions

### Description
This Lab solves the producer/consumer problem using semaphores and the alphabet.
<br /><br />Note: `threadsync.c` was provided by Prof. Lamble at CSUMB, and `threadSync3.c` is just my experiment for the same problem using many threads.

### To Run:
* Open Unix based terminal at file location and use "make" to generate binary files
* Then use the command `./threadSync2` to run the program

### Output Samples:
#### threadSync2 
```
a
b
c
d
e
f
g
h
i
j
k
l
m
n
o
p
q
r
s
t
u
v
w
x
y
z
Thread producer_t returned
Thread consumer_t returned
Main thread done.
```

### Output Sample with Tracers
#### threadSync2 with a buffer size of 1
```
->PUT: a   
buffer: [a]
<-GET: a   
buffer: [ ]
->PUT: b   
buffer: [b]
<-GET: b   
buffer: [ ]
->PUT: c   
buffer: [c]
<-GET: c   
buffer: [ ]
->PUT: d   
buffer: [d]
<-GET: d   
buffer: [ ]
->PUT: e   
buffer: [e]
<-GET: e   
buffer: [ ]
->PUT: f   
buffer: [f]
<-GET: f   
buffer: [ ]
->PUT: g   
buffer: [g]
<-GET: g
buffer: [ ]
->PUT: h
buffer: [h]
<-GET: h
buffer: [ ]
->PUT: i
buffer: [i]
<-GET: i
buffer: [ ]
->PUT: j
buffer: [j]
<-GET: j
buffer: [ ]
->PUT: k
buffer: [k]
<-GET: k
buffer: [ ]
->PUT: l
buffer: [l]
<-GET: l
buffer: [ ]
->PUT: m
buffer: [m]
<-GET: m
buffer: [ ]
->PUT: n
buffer: [n]
<-GET: n
buffer: [ ]
->PUT: o
buffer: [o]
<-GET: o
buffer: [ ]
->PUT: p
buffer: [p]
<-GET: p
buffer: [ ]
->PUT: q
buffer: [q]
<-GET: q
buffer: [ ]
->PUT: r
buffer: [r]
<-GET: r
buffer: [ ]
->PUT: s
buffer: [s]
<-GET: s
buffer: [ ]
->PUT: t
buffer: [t]
<-GET: t
buffer: [ ]
->PUT: u
buffer: [u]
<-GET: u
buffer: [ ]
->PUT: v
buffer: [v]
<-GET: v
buffer: [ ]
->PUT: w
buffer: [w]
<-GET: w
buffer: [ ]
->PUT: x
buffer: [x]
<-GET: x
buffer: [ ]
->PUT: y
buffer: [y]
<-GET: y
buffer: [ ]
->PUT: z
buffer: [z]
<-GET: z
buffer: [ ]
Thread producer_t returned
Thread consumer_t returned 
Main thread done.
```
#### threadSync2 with a buffer size of 6
```
->PUT: a        
buffer: [a]     
->PUT: b        
buffer: [ab]    
->PUT: c        
buffer: [abc]   
->PUT: d        
buffer: [abcd]  
->PUT: e        
buffer: [abcde] 
->PUT: f        
buffer: [abcdef]
<-GET: a        
buffer: [ bcdef]
<-GET: b        
buffer: [  cdef]
<-GET: c        
buffer: [   def]
<-GET: d        
buffer: [    ef]
<-GET: e        
buffer: [     f]
<-GET: f        
buffer: [      ]
->PUT: g
buffer: [g     ]
->PUT: h
buffer: [gh    ]
->PUT: i
buffer: [ghi   ]
->PUT: j
buffer: [ghij  ]
->PUT: k
buffer: [ghijk ]
->PUT: l
buffer: [ghijkl]
<-GET: g
buffer: [ hijkl]
<-GET: h
buffer: [  ijkl]
<-GET: i
buffer: [   jkl]
<-GET: j
buffer: [    kl]
<-GET: k
buffer: [     l]
<-GET: l
buffer: [      ]
->PUT: m
buffer: [m     ]
->PUT: n
buffer: [mn    ]
->PUT: o
buffer: [mno   ]
->PUT: p
buffer: [mnop  ]
->PUT: q
buffer: [mnopq ]
->PUT: r
buffer: [mnopqr]
<-GET: m
buffer: [ nopqr]
<-GET: n
buffer: [  opqr]
<-GET: o
buffer: [   pqr]
<-GET: p
buffer: [    qr]
<-GET: q
buffer: [     r]
<-GET: r
buffer: [      ]
->PUT: s
buffer: [s     ]
->PUT: t
buffer: [st    ]
->PUT: u
buffer: [stu   ]
->PUT: v
buffer: [stuv  ]
->PUT: w
buffer: [stuvw ]
->PUT: x
buffer: [stuvwx]
<-GET: s
buffer: [ tuvwx]
<-GET: t
buffer: [  uvwx]
<-GET: u
buffer: [   vwx]
<-GET: v
buffer: [    wx]
<-GET: w
buffer: [     x]
<-GET: x
buffer: [      ]
->PUT: y
buffer: [y     ]
->PUT: z
buffer: [yz    ]
<-GET: y
buffer: [ z    ]
<-GET: z
buffer: [      ]
Thread producer_t returned
Thread consumer_t returned
Main thread done.
```