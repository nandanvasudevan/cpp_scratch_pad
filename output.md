# With the minimum required regex for each type
## Run 1
```
-------------------------------------------------------------------------------
Phone number
  IN
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/main.cpp:18
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No spaces                                      100            19     7.2504 ms
                                        3.91609 us    3.88497 us    3.95827 us
                                        183.237 ns    141.208 ns    248.477 ns

With spaces                                    100            15      7.302 ms
                                        5.14852 us    5.04967 us    5.28801 us
                                        592.527 ns     459.79 ns    776.286 ns

With -                                         100            17      7.446 ms
                                        4.32492 us     4.2913 us    4.38131 us
                                        217.791 ns    150.757 ns    377.317 ns

With spaces & -                                100            14     7.3276 ms
                                        6.19627 us    5.82123 us    6.68265 us
                                        2.17217 us    1.77539 us    2.56685 us


===============================================================================
All tests passed (4 assertions in 1 test case)
```

## Run 2
```
-------------------------------------------------------------------------------
Phone number
  IN
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/main.cpp:18
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No spaces                                      100            20       6.73 ms
                                        3.21361 us    3.18912 us    3.25008 us
                                         151.11 ns    107.552 ns    223.209 ns

With spaces                                    100            17       6.97 ms
                                        4.24563 us    4.15651 us    4.37327 us
                                        539.483 ns    407.919 ns    719.633 ns

With -                                         100            18     6.7608 ms
                                        3.91212 us    3.85673 us    3.99198 us
                                        336.282 ns    256.888 ns    468.177 ns

With spaces & -                                100            15      6.987 ms
                                        4.51435 us    4.47262 us    4.57015 us
                                          245.2 ns    193.453 ns    333.397 ns


===============================================================================
All tests passed (4 assertions in 1 test case)
```

# With the most complex regex, same for all
```
-------------------------------------------------------------------------------
Phone number
  IN
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/main.cpp:18
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No spaces                                      100            18     4.4748 ms 
                                        3.78445 us    3.62799 us    3.96168 us 
                                        849.881 ns    750.233 ns    956.967 ns 
                                                                               
With spaces                                    100            16     4.5744 ms 
                                        2.87022 us      2.837 us      2.936 us 
                                        229.812 ns     129.36 ns    375.723 ns 
                                                                               
With -                                         100            15      4.629 ms 
                                         2.9265 us    2.89689 us    2.99171 us 
                                        213.087 ns    119.176 ns    412.695 ns 
                                                                               
With spaces & -                                100            14     4.5206 ms 
                                        2.95628 us    2.93048 us    3.00667 us 
                                        178.545 ns    110.735 ns     336.47 ns 
                                                                               

===============================================================================
All tests passed (4 assertions in 1 test case)
```