# Numeric algorithms
```
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scratch_pad_test is a Catch v3.0.0-preview.3 host application.
Run with -? for options

Randomness seeded to: 2422618635

-------------------------------------------------------------------------------
iota
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:33
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
iota                                           100           662     4.0382 ms 
                                        61.8978 ns    61.8519 ns    61.9848 ns 
                                       0.309999 ns   0.170033 ns   0.464064 ns 
                                                                               

-------------------------------------------------------------------------------
generate
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:45
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
generate                                       100           554     4.0442 ms 
                                        80.2427 ns    80.1033 ns    80.5037 ns 
                                       0.946013 ns   0.555704 ns    1.40739 ns 
                                                                               

-------------------------------------------------------------------------------
accumulators
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:56
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
accumulate - add                               100           446     4.0586 ms 
                                         86.643 ns    86.2389 ns    87.2215 ns 
                                        2.41977 ns    1.83148 ns    3.12437 ns 
                                                                               
accumulate - multiply                          100           443     4.0756 ms 
                                        96.8174 ns    92.2727 ns    103.342 ns 
                                        27.4142 ns    20.4709 ns    34.6021 ns 
                                                                               
reduce - add                                   100           586     4.0434 ms 
                                        65.2968 ns    64.8284 ns    66.0126 ns 
                                        2.89778 ns     2.1135 ns    4.26577 ns 
                                                                               
reduce - multiply                              100           584      4.088 ms 
                                        64.9606 ns    64.9076 ns    65.0588 ns 
                                        0.35701 ns   0.202586 ns   0.529313 ns 
                                                                               

-------------------------------------------------------------------------------
adjacent_difference
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:84
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
adjacent difference                            100           416     4.0768 ms 
                                        99.5151 ns    98.2429 ns    100.956 ns 
                                        6.90068 ns    5.53612 ns    9.56094 ns 
                                                                               

-------------------------------------------------------------------------------
inner_product
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:101
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
inner_product                                  100           311     4.0741 ms 
                                        124.285 ns    123.244 ns    125.934 ns 
                                        6.58324 ns    4.72705 ns    11.2628 ns 
                                                                               

-------------------------------------------------------------------------------
transform_reduce
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:138
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
transform_reduce                               100           348     4.0716 ms 
                                        107.934 ns     107.13 ns     109.09 ns 
                                        4.88162 ns    3.84434 ns    6.65437 ns 
                                                                               

===============================================================================
test cases: 6 | 6 passed
assertions: - none -
```