# Numeric algorithms

<details>
<summary>Benchmark results</summary>

```c++
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
</details>

# std::par is not that good!
Always slower than `std::accumulate` and `std::reduce` without any execution policies.

<details>
<summary>Benchmark results</summary>

```c++
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scratch_pad_test is a Catch v3.0.0-preview.3 host application.
Run with -? for options

Randomness seeded to: 3519673913

-------------------------------------------------------------------------------
accumulators
  Normal execution
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:73
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
accumulate - add                               100             1    10.4468 ms 
                                         92.756 us    92.0961 us    93.3969 us 
                                        3.34205 us     3.0432 us    3.68202 us 
                                                                               
accumulate - multiply                          100             1     9.9123 ms 
                                        88.6793 us     88.172 us    89.2391 us 
                                        2.71132 us    2.39379 us    3.08731 us 
                                                                               
reduce - add                                   100             1     5.8057 ms 
                                        50.9555 us    50.7221 us     51.261 us 
                                        1.35434 us    1.09803 us     1.7306 us 
                                                                               
reduce - multiply                              100             1     6.0593 ms 
                                        53.3025 us     53.078 us    53.5196 us 
                                         1.1356 us    964.716 ns    1.45423 us 
                                                                               

Size: 10000
-------------------------------------------------------------------------------
accumulators
  std::execution::par
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:113
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
reduce - add                                   100             1    13.1593 ms 
                                        122.177 us    121.652 us    122.688 us 
                                        2.63727 us    2.39613 us    2.90825 us 
                                                                               
reduce - multiply                              100             1    12.9998 ms 
                                        123.745 us    123.093 us    124.691 us 
                                        3.95337 us    2.93767 us     5.7433 us 
                                                                               

===============================================================================
test cases: 1 | 1 passed
assertions: - none -
```
</details>

## for_each vs reduce
The `std::for_each` algorithm seems to respond better to modifications in execution policy.

In the example of XOR, non-sequential execution was **almost thrice as fast** (parallel helped a bit) 
than sequential or no policy variants.

However, it is the same old for `std::reduce` with **no-policy being the fastest**.

<details>
<summary>Benchmark results</summary>

```c++
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scratch_pad_test is a Catch2 v3.0.0-preview.4 host application.
Run with -? for options

Randomness seeded to: 928077540

-------------------------------------------------------------------------------
accumulators
  std::execution::par
  std::for_each
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:113
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No policy                                      100             1     9.6265 ms 
                                         59.361 us    59.2471 us    59.5617 us 
                                        751.825 ns    509.327 ns    1.19671 us 
                                                                               
Sequential                                     100             1     6.3999 ms 
                                        57.4006 us    57.2318 us    57.6433 us 
                                        1.02222 us    777.218 ns    1.26438 us 
                                                                               
Un-sequential                                  100             2     6.3872 ms 
                                        26.2431 us    25.6457 us    26.8152 us 
                                         2.9694 us    2.81181 us    3.06365 us 
                                                                               
Parallel                                       100             1     6.3127 ms 
                                        56.1166 us     55.964 us    56.4133 us 
                                        1.04948 us    618.989 ns    1.91024 us 
                                                                               
Parallel un-sequential                         100             2     6.3086 ms 
                                        28.5069 us    28.4253 us    28.5933 us 
                                        428.195 ns    379.464 ns    543.032 ns 
                                                                               

-------------------------------------------------------------------------------
accumulators
  std::execution::par
  std::reduce
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:171
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No policy                                      100             2      7.505 ms 
                                        32.8872 us    32.7192 us    33.1661 us 
                                        1.07644 us    725.819 ns      1.967 us 
                                                                               
Sequential                                     100             1      6.926 ms 
                                        48.9318 us    48.7728 us    49.1175 us 
                                        876.651 ns    759.424 ns    1.22789 us 
                                                                               
Un-sequential                                  100             1     9.3556 ms 
                                         88.447 us    88.2257 us    88.6884 us 
                                        1.18129 us    1.10354 us    1.28753 us 
                                                                               
Parallel                                       100             1     5.5609 ms 
                                        49.6951 us    49.4041 us    50.0184 us 
                                        1.55591 us    1.42439 us     1.8878 us 
                                                                               
Parallel un-sequential                         100             1     9.1912 ms 
                                        87.6513 us    87.5655 us    87.8266 us 
                                         600.31 ns    337.826 ns    962.908 ns 
                                                                               

===============================================================================
All tests passed (1 assertion in 1 test case)


Process finished with exit code 0
```
</details>


### Huge vector!
A vector with 200'000'000 items.

`std::for_each` is still so much faster!

<details>
<summary>Benchmark results</summary>

```c++
Vector size: 200000000
for-each accumulator pre-reset: 1

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scratch_pad_test is a Catch2 v3.0.0-preview.4 host application.
Run with -? for options

Randomness seeded to: 2292055570

-------------------------------------------------------------------------------
accumulators
  std::execution::par
  std::for_each
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:122
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No policy                                      100             1     2.03273 m 
                                         1.37019 s     1.36189 s     1.37856 s 
                                        42.5896 ms    35.4241 ms    56.2441 ms 
                                                                               
Sequential                                     100             1     2.23856 m 
                                         1.52019 s     1.48791 s     1.55091 s 
                                        160.287 ms    149.574 ms    170.966 ms 
                                                                               
Un-sequential                                  100             1     1.11199 m 
                                        798.151 ms    783.936 ms    812.022 ms 
                                        71.8176 ms    61.8106 ms    84.6458 ms 
                                                                               
Parallel                                       100             1     2.10476 m 
                                         1.51291 s     1.48273 s     1.54173 s 
                                        150.221 ms     138.78 ms    161.374 ms 
                                                                               
Parallel un-sequential                         100             1     1.10153 m 
                                        807.043 ms    797.152 ms    814.331 ms 
                                        43.0654 ms    33.6113 ms    54.5913 ms 
                                                                               

Vector size: 200000000
-------------------------------------------------------------------------------
accumulators
  std::execution::par
  std::reduce
-------------------------------------------------------------------------------
/home/nandanv/code/C++/scratch_pad/src/numeric.cpp:170
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
No policy                                      100             1     2.18182 m 
                                         1.37452 s     1.34895 s     1.39815 s 
                                        125.164 ms    114.851 ms    135.933 ms 
                                                                               
Sequential                                     100             1     3.73969 m 
                                         2.11204 s     2.07917 s     2.14216 s 
                                        160.878 ms    147.482 ms    173.707 ms 
                                                                               
Un-sequential                                  100             1       3.161 m 
                                         2.13319 s     2.09989 s     2.16396 s 
                                         163.31 ms    150.229 ms    175.634 ms 
                                                                               
Parallel                                       100             1     3.71497 m 
                                         2.09728 s     2.06288 s     2.12985 s 
                                         170.57 ms    159.008 ms    182.118 ms 
                                                                               
Parallel un-sequential                         100             1     3.96575 m 
                                         2.20307 s      2.1661 s     2.23776 s 
                                        183.075 ms    171.397 ms    193.261 ms 
```

</details>