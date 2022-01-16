# CTRE vs std::regex
```
-------------------------------------------------------------------------------
std::regex Phone number
  IN
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/main.cpp:22
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No spaces                                      100            20      7.484 ms 
                                        3.73052 us    3.70071 us    3.78884 us 
                                        205.463 ns     123.46 ns    383.109 ns 
                                                                               
With spaces                                    100            18     7.4322 ms 
                                        4.29475 us    4.24527 us    4.36524 us 
                                        299.407 ns     226.59 ns    388.988 ns 
                                                                               
With -                                         100            20      7.388 ms 
                                        3.65157 us    3.63367 us    3.68155 us 
                                        115.523 ns    79.5987 ns    196.244 ns 
                                                                               
With spaces & -                                100            16     7.3072 ms 
                                        4.67185 us    4.60889 us    4.77102 us 
                                        397.467 ns    288.963 ns     634.91 ns 
                                                                               

-------------------------------------------------------------------------------
CTRE Phone number
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/main.cpp:71
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No spaces                                      100            71     7.1994 ms 
                                        1.09503 us    1.08961 us    1.10165 us 
                                         30.457 ns    25.3222 ns    37.4321 ns 
                                                                               
With spaces                                    100            79      7.268 ms 
                                        940.681 ns    936.724 ns    949.823 ns 
                                         29.125 ns    14.9878 ns    60.3481 ns 
                                                                               
With -                                         100            70      7.203 ms 
                                        1.06936 us      1.063 us    1.07572 us 
                                        32.3717 ns    26.2117 ns    43.4359 ns 
                                                                               
With - & space                                 100            77     7.2149 ms 
                                        1.03563 us     1.0249 us    1.04922 us 
                                        61.4934 ns    49.8782 ns    79.2097 ns 
                                                                               

===============================================================================
All tests passed (8 assertions in 2 test cases)
```

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