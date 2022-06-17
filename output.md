# vs `Glib::ustring`

To conclude, {fmt} is fast!

<details>
<summary>Benchmark result</summary>

```
Randomness seeded to: 2851490110

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
{fmt}                                          100          1260       4.41 ms 
                                        34.3702 ns     34.207 ns     34.626 ns 
                                        1.02637 ns   0.743215 ns    1.36252 ns 
                                                                               
{fmt} to Glib::ustring                         100           480      4.416 ms 
                                        90.7163 ns    90.4946 ns    91.3477 ns 
                                        1.74672 ns    0.59582 ns    3.71523 ns 
                                                                               
Glib::ustring::format                          100           108     4.4388 ms 
                                        398.697 ns    397.382 ns    401.208 ns 
                                        8.86411 ns    4.84562 ns    13.5393 ns 
                                                                               
Glib::ustring::compose                         100            65     4.4655 ms 
                                        637.088 ns     630.33 ns    651.782 ns 
                                        48.1325 ns    27.7148 ns    88.6021 ns 
                                                                               

-------------------------------------------------------------------------------
Float format
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:42
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt}                                          100           457     4.4329 ms 
                                        92.8359 ns    92.3064 ns    93.5906 ns 
                                        3.18763 ns     2.4274 ns    3.95575 ns 
                                                                               
{fmt} to Glib::ustring                         100           282     4.4274 ms 
                                         151.58 ns    150.278 ns    153.198 ns 
                                        7.38239 ns    6.14967 ns    8.49176 ns 
                                                                               
Glib::ustring::format                          100            53     4.4732 ms 
                                        804.482 ns    794.823 ns    814.962 ns 
                                        51.6408 ns    46.4237 ns    60.2149 ns 
                                                                               
Glib::ustring::compose                         100            41      4.469 ms 
                                        997.596 ns    987.292 ns    1.01223 us 
                                        61.7331 ns    47.8604 ns    86.6906 ns 
                                                                               

===============================================================================
All tests passed (1 assertion in 3 test cases)

```

</details>
