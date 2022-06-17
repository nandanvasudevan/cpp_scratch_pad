# vs Glib::ustring::compose

To conclude, {fmt} is fast!

<details>
<summary>Benchmark result</summary>

```
Randomness seeded to: 657346094

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
{fmt}                                          100          1121     4.1477 ms 
                                        35.1932 ns    34.9546 ns    35.4883 ns 
                                        1.34887 ns    1.14997 ns    1.70905 ns 
                                                                               
Glib::ustring                                  100            64     4.2432 ms 
                                        619.245 ns    612.447 ns    632.942 ns 
                                        47.1999 ns    29.0875 ns    85.1936 ns 
                                                                               

-------------------------------------------------------------------------------
Float format
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:29
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt}                                          100           409     4.2127 ms 
                                        98.1801 ns    97.2919 ns    99.0528 ns 
                                        4.47992 ns    4.05987 ns    5.12564 ns 
                                                                               
Glib::ustring                                  100            39     4.2432 ms 
                                        986.606 ns     976.77 ns    1.01717 us 
                                        80.4378 ns    30.9592 ns    177.106 ns 
                                                                               

===============================================================================
All tests passed (1 assertion in 3 test cases)
```

</details>

