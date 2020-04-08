# Lab 5 Instructions

### Description
This Lab multiplies two matrices using multiple threads

### To Run:
* Open Unix based terminal at file location and use "make" to generate binary file.
* Then use the command `./matrix_multiplication` to run the program. 
    
### Output Samples:
#### Thread Hello
```
Hello from thread -239270144 with iteration 1
Hello from thread -247724288 with iteration 2
Hello from thread -256178432 with iteration 3
Hello from thread -335608064 with iteration 4
Hello from thread -344062208 with iteration 5
Hello from thread -352516352 with iteration 6
Hello from thread -360970496 with iteration 7
Hello from thread -369424640 with iteration 8
Hello from thread -377878784 with iteration 9
Thread 0 returned
Thread 1 returned
Thread 2 returned
Thread 3 returned
Thread 4 returned
Thread 5 returned
Hello from thread -386332928 with iteration 5
Thread 6 returned
Thread 7 returned
Thread 8 returned
Thread 9 returned
Main thread done.
```

#### Thread Hello Fixed
```
Hello from thread 1031603968 with iteration 0
Hello from thread 1023149824 with iteration 1
Hello from thread 1006241536 with iteration 3
Hello from thread 1014695680 with iteration 2
Hello from thread 997787392 with iteration 4
Hello from thread 989333248 with iteration 5
Hello from thread 980879104 with iteration 6
Hello from thread 972424960 with iteration 7
Hello from thread 963970816 with iteration 8
Hello from thread 955516672 with iteration 9
Thread 0 returned
Thread 1 returned
Thread 2 returned
Thread 3 returned
Thread 4 returned
Thread 5 returned
Thread 6 returned
Thread 7 returned
Thread 8 returned
Thread 9 returned
Main thread done.
```
#### Matrix Multiplication
```
Matrix A:
 9.00     1.00     5.00     4.00     9.00     2.00     9.00     4.00     0.00     4.00    
 0.00     6.00     7.00     8.00     4.00     2.00     9.00     9.00     2.00     0.00    
 1.00     6.00     2.00     1.00     7.00     6.00     7.00     9.00     8.00     5.00    
 2.00     0.00     6.00     0.00     4.00     7.00     2.00     5.00     3.00     2.00    
 1.00     4.00     8.00     9.00     2.00     3.00     3.00     3.00     4.00     6.00    
 3.00     5.00     4.00     7.00     8.00     1.00     4.00     7.00     3.00     4.00    
 3.00     5.00     4.00     1.00     5.00     0.00     1.00     9.00     8.00     4.00    
 4.00     9.00     0.00     4.00     0.00     5.00     7.00     4.00     8.00     3.00    
 2.00     4.00     0.00     6.00     1.00     9.00     8.00     7.00     8.00     1.00    
 4.00     3.00     8.00     8.00     7.00     4.00     1.00     8.00     5.00     1.00    

Matrix B: 
 14.00    9.00     10.00    5.00     14.00    13.00    2.00     13.00    7.00     0.00    
 17.00    11.00    16.00    19.00    17.00    8.00     0.00     7.00     17.00    19.00   
 10.00    1.00     14.00    19.00    12.00    1.00     5.00     15.00    9.00     12.00   
 16.00    4.00     2.00     6.00     1.00     8.00     11.00    15.00    1.00     10.00   
 15.00    10.00    1.00     12.00    10.00    11.00    12.00    10.00    18.00    1.00    
 1.00     1.00     3.00     16.00    12.00    15.00    17.00    17.00    10.00    19.00   
 9.00     18.00    15.00    3.00     16.00    8.00     11.00    8.00     3.00     5.00    
 18.00    10.00    15.00    0.00     14.00    17.00    11.00    6.00     0.00     1.00    
 0.00     13.00    2.00     3.00     1.00     14.00    10.00    19.00    3.00     12.00   
 10.00    5.00     10.00    17.00    0.00     6.00     5.00     12.00    6.00     8.00    

Matrix C:
 587.00   427.00   434.00   418.00   521.00   455.00   392.00   527.00   362.00   247.00  
 605.00   425.00   494.00   408.00   530.00   446.00   423.00   505.00   298.00   398.00  
 538.00   502.00   467.00   473.00   529.00   589.00   490.00   594.00   389.00   449.00  
 283.00   206.00   260.00   333.00   329.00   336.00   318.00   402.00   237.00   276.00  
 480.00   286.00   373.00   482.00   337.00   359.00   352.00   557.00   279.00   435.00  
 602.00   396.00   402.00   429.00   439.00   459.00   387.00   515.00   348.00   335.00  
 469.00   372.00   379.00   347.00   376.00   443.00   307.00   461.00   284.00   300.00  
 443.00   441.00   418.00   391.00   449.00   485.00   353.00   528.00   298.00   465.00  
 424.00   428.00   375.00   343.00   454.00   553.00   485.00   577.00   250.00   459.00  
 587.00   351.00   390.00   460.00   462.00   505.00   442.00   614.00   349.00   397.00  
Main Done
```