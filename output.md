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

# Custom `double` formatter with variable decimals

![Graph](fmt_vs_glib.svg)

<details>
<summary>Benchmark result</summary>

```
Randomness seeded to: 3166038873

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scratch_pad_test is a Catch2 v3.0.1 at devel commit: 3a18a688a07e3f7217d7a1b0ae45a324edfdef52 host application.
Run with -? for options

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 0
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           267     4.6992 ms 
                                        160.436 ns    159.961 ns     160.97 ns 
                                        2.55535 ns    2.23234 ns    3.38473 ns 
                                                                               
Glib::ustring::format                          100            60      4.728 ms 
                                        721.144 ns     715.02 ns    740.929 ns 
                                        50.3211 ns    18.7495 ns    111.462 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 1
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           226     4.6782 ms 
                                        188.081 ns    187.474 ns    189.228 ns 
                                        4.10007 ns    2.42304 ns    6.21416 ns 
                                                                               
Glib::ustring::format                          100            58     4.7328 ms 
                                        761.761 ns    755.236 ns    782.977 ns 
                                        54.4486 ns    19.5432 ns    122.018 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 2
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           221     4.6852 ms 
                                        217.658 ns    207.064 ns     231.98 ns 
                                        62.4155 ns    49.4902 ns    74.6244 ns 
                                                                               
Glib::ustring::format                          100            49     4.7334 ms 
                                         892.36 ns    886.816 ns    907.175 ns 
                                        42.8126 ns    16.4697 ns    88.0432 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 3
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           216     4.6872 ms 
                                        196.177 ns    195.598 ns    197.008 ns 
                                        3.51938 ns    2.75664 ns    5.56855 ns 
                                                                               
Glib::ustring::format                          100            48     4.7376 ms 
                                        910.143 ns      905.1 ns    921.239 ns 
                                        36.2636 ns    20.2978 ns    71.8885 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 4
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           183     4.7031 ms 
                                        243.837 ns    243.301 ns    246.025 ns 
                                        4.73358 ns   0.843196 ns    10.9908 ns 
                                                                               
Glib::ustring::format                          100            41     4.6904 ms 
                                        1.16952 us    1.16687 us    1.17604 us 
                                        19.9771 ns    10.0717 ns     41.345 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 5
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           184      4.692 ms 
                                        253.154 ns     252.02 ns    256.032 ns 
                                         8.1334 ns    1.08144 ns    14.9239 ns 
                                                                               
Glib::ustring::format                          100            38     4.7234 ms 
                                         1.2964 us    1.28084 us    1.35436 us 
                                        134.446 ns    25.9436 ns    308.062 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 6
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           181      4.706 ms 
                                        247.541 ns    247.384 ns    247.895 ns 
                                        1.14289 ns   0.500534 ns    2.17291 ns 
                                                                               
Glib::ustring::format                          100            41     4.7273 ms 
                                        1.11373 us    1.10986 us    1.12732 us 
                                        32.9249 ns    10.3615 ns    74.8728 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 7
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           154      4.697 ms 
                                        302.376 ns    301.623 ns    304.946 ns 
                                        6.08793 ns   0.590855 ns    13.6948 ns 
                                                                               
Glib::ustring::format                          100            40      4.708 ms 
                                        1.16786 us     1.1644 us    1.17919 us 
                                         28.778 ns    10.1282 ns    64.3731 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 8
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           187      4.675 ms 
                                        245.389 ns    245.093 ns    246.181 ns 
                                        2.27405 ns   0.691029 ns    4.57514 ns 
                                                                               
Glib::ustring::format                          100            39     4.6878 ms 
                                        1.11239 us     1.1009 us    1.15917 us 
                                        107.624 ns    11.4879 ns    255.521 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 9
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           190      4.693 ms 
                                        237.288 ns     237.11 ns    237.651 ns 
                                        1.23717 ns    0.70775 ns    2.01073 ns 
                                                                               
Glib::ustring::format                          100            39     4.7229 ms 
                                        1.15924 us    1.15649 us    1.16389 us 
                                        17.8764 ns      11.31 ns    27.8077 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 10
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           190      4.674 ms 
                                        245.028 ns    244.698 ns    246.198 ns 
                                        2.74505 ns   0.452152 ns    6.11857 ns 
                                                                               
Glib::ustring::format                          100            39     4.7619 ms 
                                        1.16765 us    1.16407 us    1.18105 us 
                                        31.4007 ns     7.6961 ns    72.7698 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 11
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           189     4.7061 ms 
                                        239.136 ns    238.605 ns    241.178 ns 
                                        4.61397 ns    1.06357 ns    10.6271 ns 
                                                                               
Glib::ustring::format                          100            40      4.764 ms 
                                        1.18733 us    1.18121 us    1.21125 us 
                                        55.4638 ns    9.92593 ns    130.395 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 12
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           184      4.692 ms 
                                        240.973 ns    240.838 ns    241.273 ns 
                                         0.9742 ns   0.395332 ns    1.68287 ns 
                                                                               
Glib::ustring::format                          100            39     4.7151 ms 
                                        1.25658 us    1.24424 us    1.28807 us 
                                        94.0393 ns    46.0754 ns    199.215 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 13
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           177     4.7082 ms 
                                        249.592 ns     249.34 ns    250.138 ns 
                                        1.80861 ns    1.00952 ns    2.94284 ns 
                                                                               
Glib::ustring::format                          100            39     4.7112 ms 
                                        1.21539 us    1.20604 us    1.25739 us 
                                        86.4142 ns    10.1955 ns    204.424 ns 
                                                                               

-------------------------------------------------------------------------------
Custom decimals
  Decimals: 14
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/vs_glib_ustring.cpp:85
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
{fmt} to Glib::ustring                         100           162     4.6818 ms 
                                        290.847 ns    285.663 ns    301.634 ns 
                                        36.4047 ns    20.6214 ns    60.8661 ns 
                                                                               
Glib::ustring::format                          100            37     4.7656 ms 
                                        1.28352 us    1.27545 us    1.31469 us 
                                        73.7173 ns     11.856 ns     173.58 ns 
                                                                               

===============================================================================
All tests passed (1 assertion in 2 test cases)
```


</details>