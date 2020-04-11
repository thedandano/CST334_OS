# Lab 6 Instructions

### Description
This Lab solves the producer/consumer problem using the alphabet.
<br /><br />Note: threadsync.c was provided by Prof. Lamble at CSUMB, and threadSync3 is just my experiment for the same problem using many threads.

### To Run:
* Open Unix based terminal at file location and use "make" to generate binary files
* Then use the command `./threadSync2` to run program

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
Thread 0 returned
Thread 1 returned
Main thread done.
```

### Output Sample with Tracers
#### threadSync2 with a buffer size of 1
```
->PUT: a   
buffer: [a]
<-GET: a   
->PUT: b   
buffer: [b]
<-GET: b   
->PUT: c   
buffer: [c]
<-GET: c   
->PUT: d   
buffer: [d]
<-GET: d   
->PUT: e   
buffer: [e]
<-GET: e   
->PUT: f   
buffer: [f]
<-GET: f   
->PUT: g
buffer: [g]
<-GET: g
->PUT: h
buffer: [h]
<-GET: h
->PUT: i
buffer: [i]
<-GET: i
->PUT: j
buffer: [j]
<-GET: j
->PUT: k
buffer: [k]
<-GET: k
->PUT: l
buffer: [l]
<-GET: l
->PUT: m
buffer: [m]
<-GET: m
->PUT: n
buffer: [n]
<-GET: n
->PUT: o
buffer: [o]
<-GET: o
->PUT: p
buffer: [p]
<-GET: p
->PUT: q
buffer: [q]
<-GET: q
->PUT: r
buffer: [r]
<-GET: r
->PUT: s
buffer: [s]
<-GET: s
->PUT: t
buffer: [t]
<-GET: t
->PUT: u
buffer: [u]
<-GET: u
->PUT: v
buffer: [v]
<-GET: v
->PUT: w
buffer: [w]
<-GET: w
->PUT: x
buffer: [x]
<-GET: x
->PUT: y
buffer: [y]
<-GET: y
->PUT: z
buffer: [z]
<-GET: z
buffer: []
Thread 0 returned
Thread 1 returned
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
<-GET: b        
<-GET: c        
<-GET: d        
<-GET: e        
<-GET: f        
->PUT: g        
buffer: [g]     
->PUT: h        
buffer: [gh]    
->PUT: i        
buffer: [ghi]   
->PUT: j
buffer: [ghij]
->PUT: k
buffer: [ghijk]
->PUT: l
buffer: [ghijkl]
<-GET: g
<-GET: h
<-GET: i
<-GET: j
<-GET: k
<-GET: l
->PUT: m
buffer: [m]
->PUT: n
buffer: [mn]
->PUT: o
buffer: [mno]
->PUT: p
buffer: [mnop]
->PUT: q
buffer: [mnopq]
->PUT: r
buffer: [mnopqr]
<-GET: m
<-GET: n
<-GET: o
<-GET: p
<-GET: q
<-GET: r
->PUT: s
buffer: [s]
->PUT: t
buffer: [st]
->PUT: u
buffer: [stu]
->PUT: v
buffer: [stuv]
->PUT: w
buffer: [stuvw]
->PUT: x
buffer: [stuvwx]
<-GET: s
<-GET: t
<-GET: u
<-GET: v
<-GET: w
<-GET: x
->PUT: y
buffer: [y]
->PUT: z
buffer: [yz]
<-GET: y
<-GET: z
buffer: []
Thread 0 returned
Thread 1 returned
Main thread done.
```