# vs `Glib::ustring`

To conclude, {fmt} is fast!

<details>
<summary>Benchmark result</summary>

```
Randomness seeded to: 1091902101

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scratch_pad_test is a Catch2 v3.0.1 at devel commit: 3a18a688a07e3f7217d7a1b0ae45a324edfdef52 host application.
Run with -? for options

-------------------------------------------------------------------------------
Simple format
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:15
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt}                                          100          1108     4.2104 ms 
                                        34.9526 ns    34.6944 ns    35.2971 ns 
                                         1.5043 ns    1.21483 ns    1.81513 ns 
                                                                               
Glib::ustring::format                          100            95     4.2655 ms 
                                         408.94 ns    405.797 ns    418.101 ns 
                                        24.9096 ns    10.0009 ns    50.2671 ns 
                                                                               
Glib::ustring::compose                         100            58     4.3036 ms 
                                        688.404 ns    682.273 ns    703.941 ns 
                                        46.6584 ns    23.8107 ns    97.1891 ns 
                                                                               

-------------------------------------------------------------------------------
Float format
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:36
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt}                                          100           404      4.242 ms 
                                        93.9265 ns    93.5965 ns    94.6084 ns 
                                        2.31667 ns    1.34004 ns     3.8654 ns 
                                                                               
Glib::ustring::format                          100            49     4.3071 ms 
                                        839.544 ns    832.326 ns    862.993 ns 
                                         59.769 ns    20.8922 ns    133.766 ns 
                                                                               
Glib::ustring::compose                         100            36     4.3416 ms 
                                        1.09227 us    1.08156 us    1.13737 us 
                                        95.8451 ns    15.6824 ns    224.344 ns 
                                                                               

===============================================================================
All tests passed (1 assertion in 3 test cases)

```

</details>
